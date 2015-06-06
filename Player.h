#ifndef PLAYER
#define PLAYER

#include <QGraphicsRectItem>
#include <QObject>

class Player: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
};

#endif // PLAYER

