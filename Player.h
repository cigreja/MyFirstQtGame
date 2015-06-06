#ifndef PLAYER
#define PLAYER

#include <QGraphicsRectItem>

class Player: public QGraphicsRectItem{
public:
    void keyPressEvent(QKeyEvent * event);
};

#endif // PLAYER

