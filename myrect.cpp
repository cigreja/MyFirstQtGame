#include "bullet.h"
#include "myrect.h"
//#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>

void MyRect::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        setPos(x()-10, y());
    }
    else if (event->key() == Qt::Key_Right){
        setPos(x()+10, y());
    }
    else if (event->key() == Qt::Key_Up){
        setPos(x(), y()-10);
    }
    else if (event->key() == Qt::Key_Down){
        setPos(x(), y()+10);
    }
    else if (event->key() == Qt::Key_Space){
        // create a bullet
        Bullet * bullet = new Bullet();
        //qDebug() << "bullet created";
        scene()->addItem(bullet);
    }
}
