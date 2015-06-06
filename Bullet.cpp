#include "Bullet.h"

#include <QTimer>


Bullet::Bullet()
{
    // draw bullet
    setRect(0,0,10,50);

    // connect
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Bullet::move()
{
    // move bullet up
    setPos(x(),y() -10); // inverse y direction, not sure why
}
