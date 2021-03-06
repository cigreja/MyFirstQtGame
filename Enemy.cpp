
#include "Bullet.h"
#include "Enemy.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <stdlib.h>


Enemy::Enemy(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent)
{
    // set random x position to spawn enemy at
    int random_number = rand() % 700;
    setPos(random_number, 0);

    // draw enemy
    //setRect(0,0,100,100);
    setPixmap(QPixmap(":/enemy-sprites/enemy-ship.png"));
    // this is for changing the rotation of the image
    //setTransformOriginPoint(50,50); // size of image 50px x 50px
    //setRotation(180); // rotate 180 degrees


    // move enemies timer
    QTimer * moveTimer = new QTimer();
    QObject::connect(moveTimer, SIGNAL(timeout()), this, SLOT(move()));
    moveTimer->start(50);
}

void Enemy::move()
{
    // move enemy down
    setPos(x(),y() +5); // inverse y direction, because veiw and scene is upside down
    if (pos().y()  > 600){
        // delete item once off screen
        scene()->removeItem(this);
        delete this;
    }
}
