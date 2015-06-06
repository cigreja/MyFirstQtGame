
#include "Health.h"

#include <QFont>


Health::Health(QGraphicsItem *parent)
{
    // initialize the health to 3
    health = 3;

    // draw the Health:3
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}


void Health::decrease()
{
    // update the health
    health--;
    setPlainText(QString("Health: ") + QString::number(health));
}


int Health::getHealth()
{
    return health;
}
