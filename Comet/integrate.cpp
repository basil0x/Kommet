#include "integrate.h"
#include <cmath>
using namespace std;

double E0 = 0;
double vx, vy;
double scale;


void euler_cromer(double& x, double& y){
    double r = sqrt(x * x + y * y);
    double ax = - G * M * x / (r * r * r);
    double ay = - G * M * y / (r * r * r);

    vx += ax * dt;
    vy += ay * dt;

    x += vx * dt;
    y += vy * dt;
}

void leapfrog(double& x, double& y){
    double r = sqrt(x * x + y * y);
    double ax = - G * M * x / (r * r * r);
    double ay = - G * M * y / (r * r * r);

    vx += 0.5 * ax * dt;
    vy += 0.5 * ay * dt;

    x += vx * dt;
    y += vy * dt;

    r = sqrt(x * x + y * y);
    ax = - G * M * x / (r * r * r);
    ay = - G * M * y / (r * r * r);

    vx += 0.5 * ax * dt;
    vy += 0.5 * ay * dt;
}

std::pair<double, double> stw(double x, double y){
    // mapira koordinate u koordinatnom sistemu zvezde na koordinate na ekranu
    double absX = x * scale + starX;
    double absY = starY - scale * y;

    return std::make_pair(absX, absY);
}

std::pair<double, double> wts(double x, double y){
    // mapira koorinate sa ekrana na koordinatni sistem zvezde
    double relX = (x - starX) / scale;
    double relY = (starY - y) / scale;

    return std::make_pair(relX, relY);
}

void translatePos(double &x, double& y, Integrator func){
    // koordinate tacke -> koordinatni sistem zvezde
    auto [relX, relY] = wts(x, y);

    // pozivanje unapred odredjene metode za integraljenje
    func(relX, relY);

    // koordinatni sistem zvezde -> koordinate tacke
    auto pt = stw(relX, relY);
    x = pt.first;
    y = pt.second;
}

Integrator getIntegrator(double v0, double alpha){
    vx = v0 * cos(alpha);
    vy = v0 * sin(alpha);

    E0 = 0.5 * v0 * v0 - G * M / initialX;

    scale = (windowWidth / 5.0 - starX) / initialX;

    double v_circ = sqrt(G * M / initialX);
    //double v_esc = sqrt(2) * v_circ;
    if(v0 <= 1.1 * v_circ && alpha >= M_PI / 4)
        return &euler_cromer;
    return &leapfrog;
}

double energy(double x, double y){
    auto pt = wts(x, y);
    x = pt.first;
    y = pt.second;
    return 0.5 * (vx * vx + vy * vy) - G * M / sqrt(x * x + y * y);
}

bool collision(double x, double y){
    auto pt = wts(x, y);
    x = pt.first;
    y = pt.second;
    return sqrt(x * x + y * y) <= sunR;
}

std::pair<double, double> getV0Range(){
    double v_circ = sqrt(G * M / initialX);
    double v_esc  = sqrt(2) * v_circ;

    return {0.8 * v_circ, 1.2 * v_esc};
}

std::pair<double, double> initialPosition(){
    auto [x, y] = stw(initialX, 0);
    return {x, y};
}
