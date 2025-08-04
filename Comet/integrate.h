#ifndef _INTEGRATE_H_
#define _INTEGRATE_H_

#include <utility>

const double G = 6.67e-11;   // m^3/(s^2kg)
const double M = 1.989e30;   // kg
const double initialX = -0.75e11; // m;
const double sunR = 6.96e8;
const double dt = 60*60*24; // s

typedef void (*Integrator)(double& x, double& y);



//remove extern for compilation for now
extern int windowWidth, windowHeight;
extern int starX, starY;

extern double vx, vy;

extern double scale;

Integrator getIntegrator(double v0, double alpha);
void translatePos(double& x, double& y, Integrator func);
bool collision(double x, double y);
double energy(double x, double y);
std::pair<double, double> getV0Range();

#endif
