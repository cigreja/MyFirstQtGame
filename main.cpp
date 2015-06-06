#include <QApplication>
#include <QGraphicsScene>
//#include <QGraphicsRectItem>
#include "Player.h"
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // create an item to put into the scene
    // QGraphicsRectItem * rect = new QGraphicsRectItem();
    Player * player = new Player();
    player->setRect(0,0,100,100);

    // add the item to the scene
    scene->addItem(player);

    // make rect focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();


    // create a view
    QGraphicsView * view = new QGraphicsView(scene);

    // disable scrollbars
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // set size of scene and view
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);

    // show view
    view->show();


    return a.exec();
}

