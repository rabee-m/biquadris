#include "score.h"

Score::Score(int _lvl) : lvl(_lvl) {
}

void Score::addScore(int points) {
    score += points;
    checkHi();
}

void Score::addRowScore(int rows) {
    score += (lvl + rows) * (lvl + rows);
    checkHi();
}

void Score::addBlockGone(int blockLevel) {
    score += (blockLevel + 1) * (blockLevel + 1);
    checkHi();
}

void Score::checkHi() {
    if (score > hiScore) {
        hiScore = score;
    }
}

void Score::resetScore() {
    score = 0;
}

void Score::setLevel(int _lvl) {
    lvl = _lvl;
}

int Score::getScore() {
    return score;
}

int Score::getHiScore() {
    return hiScore;
}
