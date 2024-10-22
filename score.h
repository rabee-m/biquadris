#ifndef SCORE_H
#define SCORE_H

class Score {
    int score;
    int hiScore;
    int lvl;

public:
    Score(int _lvl);
    void addScore(int points);
    void addRowScore(int rows);        // when rows are cleared
    void addBlockGone(int blockLevel); // when the entire block is cleared
    void checkHi();                    // updates hi score
    void resetScore();
    void setLevel(int _lvl);
    int getScore();
    int getHiScore();
};
#endif
