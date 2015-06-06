#ifndef SCORE
#define SCORE

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
private:
    int score;
public:
    Score(QGraphicsItem * parent = 0);
    void increase();
    int getScore();
};

#endif // SCORE

