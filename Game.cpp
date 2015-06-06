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
    player->setRect(0,0,100,100);
    player->setPos(width()/2, height() - player->rect().height());
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // spawn enemies
    QTimer * spawnTimer = new QTimer();
    QObject:: connect(spawnTimer,SIGNAL(timeout()), player, SLOT(spawn()));
    spawnTimer->start(2000);

    // score
    score = new Score();

    // health
    health = new Health();
    health->setPos(health->x(),health->y()+25);

    // scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    scene->addItem(player);
    scene->addItem(score);
    scene->addItem(health);

    // view *Game inherits View*
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    show();
}
