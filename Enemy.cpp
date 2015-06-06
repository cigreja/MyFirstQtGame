
#include "Bullet.h"
#include "Enemy.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <stdlib.h>


Enemy::Enemy()
{
    // set random position to spawn enemy at
    int random_number = rand() % 700;
    setPos(random_number, 0);

    // draw enemy
    setRect(0,0,100,100);

    // move enemies timer
    QTimer * moveTimer = new QTimer();
    QObject::connect(moveTimer, SIGNAL(timeout()), this, SLOT(move()));
    moveTimer->start(50);
}

void Enemy::move()
{
    // move enemy down
    setPos(x(),y() +5); // inverse y direction, because veiw and scene is upside down
    if (pos().y() + rect().height() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
