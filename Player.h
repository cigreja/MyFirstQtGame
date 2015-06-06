#ifndef PLAYER
#define PLAYER

#include <QGraphicsRectItem>
#include <QMediaPlayer>
#include <QObject>

class Player: public QObject, public QGraphicsRectItem{
    Q_OBJECT
private:
    QMediaPlayer * bulletsound;
public:
    Player();
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
    void collision();
};

#endif // PLAYER

