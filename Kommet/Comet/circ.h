#ifndef CIRC_H
#define CIRC_H

#include <QWidget>

class Circ : public QWidget
{
    Q_OBJECT
public:
    explicit Circ(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

signals:
};

#endif // CIRC_H
