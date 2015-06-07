#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"
#include "Player.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <typeinfo>
#include <QTimer>

extern Game * game;

// Player
Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    // set pixmap image for player ship
    // setRect(0,0,100,100);
    setPixmap(QPixmap(":/player-sprites/player-ship.png"));

    // set bullet sound
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/gun-shot.wav"));

    // check for enemy collisions
    QTimer * collisionTimer = new QTimer();
    QObject:: connect(collisionTimer,SIGNAL(timeout()), this, SLOT(collision()));
    collisionTimer->start(250);
}

// keyPressEvent
void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        if (pos().x() < -10){
            setPos(-10, y());
        }
        else if (pos().x() > 0){
            setPos(x()-10, y());
        }
    }
    if (event->key() == Qt::Key_Right){
        if (pos().x()  < 800){
            setPos(x()+10, y());
        }
        else if (pos().x() > 800){
            setPos(800, y());
        }

    }
    if (event->key() == Qt::Key_Up){
        if (pos().y() > 0){
            setPos(x(), y()-10);
        }
        else if (pos().y() < 0){
            setPos(x(), 0);
        }
    }
    if (event->key() == Qt::Key_Down){
        if (pos().y() < 600){
            setPos(x(), y()+10);
        }
        else if (pos().y() > 600){
            setPos(x(), 600);
        }
    }
    if (event->key() == Qt::Key_Space){

        // create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);

        // play bulletsound
        if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }

    }
}

// spawn
void Player::spawn()
{
    //create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

// collision
void Player::collision()
{
    // lose health if I collide with the enemy
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i<n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            // decrease health
            game->health->decrease();
        }
    }
}

