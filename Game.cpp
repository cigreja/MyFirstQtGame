#include "Game.h"
#include <QGraphicsScene>
#include <QTimer>
//#include <QGraphicsRectItem>
#include "Player.h"
#include <QGraphicsView>


Game::Game(QWidget *parent)
{

    // player
    player = new Player();
    player->setRect(0,0,100,100);
    player->setPos(width()/2, height() - player->rect().height());
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // spawn enemies
    QTimer * timer = new QTimer();
    QObject:: connect(timer,SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    // score
    score = new Score();

    // scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    scene->addItem(player);
    scene->addItem(score);

    // view *Game inherits View*
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    show();
}
