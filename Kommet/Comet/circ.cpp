#include "circ.h"
#include <QPainter>


Circ::Circ(QWidget *parent)
    : QWidget{parent}
{
    setMinimumSize(100, 100);
}

void Circ::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Set circle color
    painter.setBrush(Qt::blue);    painter.setPen(Qt::NoPen);

    // Determine the smallest dimension to keep the circle inside bounds
    int diameter = qMin(width(), height());

    // Center the circle
    int x = (width() - diameter) / 2;
    int y = (height() - diameter) / 2;

    painter.drawEllipse(x, y, diameter, diameter);
}
