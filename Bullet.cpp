#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <typeinfo>

extern Game * game; // external global object

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    // draw bullet
    //setRect(0,0,10,50);
    setPixmap(QPixmap(":/player-sprites/player-bullet.png"));

    // connect
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Bullet::move()
{
    // move bullet up
    setPos(x(),y() -10); // inverse y direction, because veiw and scene is upside down
    if (pos().y()  < 0){
        scene()->removeItem(this);
        delete this;
    }

    // if bullet collides with enemy, destroy both and increase score
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i<n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            // remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them both
            delete colliding_items[i];
            delete this;
            // increase score
            game->score->increase();
            return;
        }
    }

}
