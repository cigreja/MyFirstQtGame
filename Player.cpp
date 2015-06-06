#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>


void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        if (pos().x() < 0){
            setPos(0, y());
        }
        else if (pos().x() > 0){
            setPos(x()-10, y());
        }
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + rect().width() < 800){
            setPos(x()+10, y());
        }
        else if (pos().x() + rect().width() > 800){
            setPos(800 - rect().width(), y());
        }

    }
    else if (event->key() == Qt::Key_Up){
        if (pos().y() > 0){
            setPos(x(), y()-10);
        }
        else if (pos().y() < 0){
            setPos(x(), 0);
        }
    }
    else if (event->key() == Qt::Key_Down){
        if (pos().y() + rect().height() < 600){
            setPos(x(), y()+10);
        }
        else if (pos().y() + rect().height() > 600){
            setPos(x(), 600 - rect().height());
        }
    }
    else if (event->key() == Qt::Key_Space){
        // create a bullet
        Bullet * bullet = new Bullet();
        //qDebug() << "bullet created";
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
    }
}

void Player::spawn()
{
    //create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
