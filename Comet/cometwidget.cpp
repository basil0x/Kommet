#include "cometwidget.h"
#include <QPainter>
#include <cmath>


CometWidget::CometWidget(QWidget *parent)
    : QWidget(parent), x(initialX), y(0)
{
    connect(&timer, &QTimer::timeout, this, &CometWidget::updatePosition);
    timer.setInterval(16); // ~60 FPS

}

void CometWidget::startSimulation(double v0, double angleDeg)
{
    windowWidth = this->width();
    windowHeight = this->height();
    starX = windowWidth / 2;
    starY = windowHeight / 2;


    integrator = getIntegrator(v0, angleDeg);

    path.clear();
    x = initialX;
    y = 0;

    double absX = x * scale + starX;
    double absY = starY - scale * y;

    x = absX;
    y = absY;

    timer.start();
}

void CometWidget::stopSimulation()
{
    timer.stop();
}

void CometWidget::updatePosition()
{

    qDebug() << "Updating position...\n";
    qDebug() << "x:" << x <<"\n";
    qDebug() << "y:" << y <<"\n";

    // Dodaj prethodnu poziciju u path
    path.append(QPointF(x, y));

    // Izračunaj novu poziciju
    translatePos(x, y, integrator);

    // Proveri sudar
    if (collision(x, y)) {
        timer.stop();
    }

    update(); // repaint
}

QPointF CometWidget::toScreen(double realX, double realY) const
{
    double screenX = starX + (realX * scale);
    double screenY = starY + (realY * scale);
    return QPointF(screenX, screenY);
}

void CometWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    // Crtanje sunca
    p.setBrush(Qt::yellow);
    p.drawEllipse(QPointF(starX, starY), 5, 5);

    // Crtanje putanje komete
    p.setPen(Qt::white);
    for (int i = 1; i < path.size(); ++i) {
        p.drawLine(path[i - 1], path[i]);
    }

    // Crtanje komete (trenutna pozicija)
    if (!path.isEmpty()) {
        p.setBrush(Qt::cyan);
        p.drawEllipse(path.last(), 3, 3);
    }
}
