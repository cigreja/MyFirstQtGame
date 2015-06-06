#ifndef GAME
#define GAME

#include "Health.h"
#include "Player.h"
#include "Score.h"

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>


class Game: public QGraphicsView {

public:
    Game(QWidget * parent = 0);
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;
};

#endif // GAME

