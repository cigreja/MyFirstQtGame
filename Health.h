#ifndef HEALTH
#define HEALTH

#include <QGraphicsTextItem>

class Health: public QGraphicsTextItem{
private:
    int health;
public:
    Health(QGraphicsItem * parent = 0);
    void decrease();
    int getHealth();
};

#endif // HEALTH

