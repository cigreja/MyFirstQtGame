#include "Bullet.h"
#include "Enemy.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <typeinfo>


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
    setPos(x(),y() -10); // inverse y direction, because veiw and scene is upside down
    if (pos().y() + rect().height() < 0){
        scene()->removeItem(this);
        delete this;
    }

    // if bullet collides with enemy, destroy both
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i<n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            // remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them both
            delete colliding_items[i];
            delete this;
            return;
        }
    }

}
