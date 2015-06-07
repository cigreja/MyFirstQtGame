#include "Game.h"
#include <QGraphicsScene>
#include <QTimer>
//#include <QGraphicsRectItem>
#include "Enemy.h"
#include "Player.h"
#include <QGraphicsView>
#include <QMediaPlayer>



Game::Game(QWidget *parent)
{

    // player
    player = new Player();
    //player->setRect(0,0,100,100);
    player->setPos(width()/2, height());
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // spawn enemies
    QTimer * spawnTimer = new QTimer();
    QObject:: connect(spawnTimer,SIGNAL(timeout()), player, SLOT(spawn()));
    spawnTimer->start(2000);

    // score
    score = new Score();
    score->setPos(score->x() +50,score->y()+50);

    // health
    health = new Health();
    health->setPos(health->x() +50,health->y()+75);

    // scene
    scene = new QGraphicsScene();
    scene->setSceneRect(50,50,950,725);
    scene->addItem(player);
    scene->addItem(score);
    scene->addItem(health);

    // set backgroung image
    setBackgroundBrush(QBrush(QImage(":/bg-images/bg-image.png")));

    // play background music
    QMediaPlayer *mPlayer = new QMediaPlayer();
    mPlayer->setMedia(QUrl("qrc:/bgm/bgm019.mp3"));
    //mPlayer->play();

    // view *Game inherits View*
    this->setScene(scene);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setFixedSize(950,725);
    this->show();
}
