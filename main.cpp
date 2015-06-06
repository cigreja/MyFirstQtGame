#include <QApplication>
#include <QGraphicsScene>
//#include <QGraphicsRectItem>
#include "myrect.h"
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // create an item to put into the scene
    // QGraphicsRectItem * rect = new QGraphicsRectItem();
    MyRect * rect = new MyRect();
    rect->setRect(0,0,100,100);

    // add the item to the scene
    scene->addItem(rect);

    // make rect focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();


    // create a view
    QGraphicsView * view = new QGraphicsView(scene);
    view->show();

    return a.exec();
}

