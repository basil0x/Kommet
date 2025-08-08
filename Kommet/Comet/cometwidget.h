#ifndef COMETWIDGET_H
#define COMETWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QVector>
#include <QPointF>
#include "integrate.h"

class CometWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CometWidget(QWidget *parent = nullptr);

    void startSimulation(double v0, double angleDeg);
    void stopSimulation();

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void updatePosition();

private:
    QTimer timer;
    QVector<QPointF> path; // istorija pozicija
    double x, y;           // trenutna pozicija na ekranu
    Integrator integrator;

    QPointF toScreen(double x, double y) const;
};

#endif // COMETWIDGET_H
