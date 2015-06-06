#ifndef PLAYER
#define PLAYER

#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QObject>

class Player: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
private:
    QMediaPlayer * bulletsound;
public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
    void collision();
};

#endif // PLAYER

