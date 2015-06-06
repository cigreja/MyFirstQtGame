#include "Score.h"

#include <QFont>


Score::Score(QGraphicsItem *parent)
{
    // initialize the score to 0
    score = 0;

    // draw the Score:0
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}


void Score::increase()
{
    // update the score
    score++;
    setPlainText(QString("Score: ") + QString::number(score));
}


int Score::getScore()
{
    return score;
}
