#include "Score.h"

#include <QFont>


Score::Score(QGraphicsItem *parent)
{
    // initialize the score to 0
    score = 0;

    // draw the text
    setPlainText(QString("Score: ") + QString::number(score)); // score
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}


void Score::increase()
{
    score++;
}


int Score::getScore()
{
    return score;
}
