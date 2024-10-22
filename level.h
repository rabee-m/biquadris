#ifndef LEVEL_H
#define LEVEL_H

#include "board.h"
using namespace std;

class Level {
protected:
    int lvl;
    int seed;
    bool read; // if we should use the file or not
    string file;
    vector<char> seq; // vector of blocks for sequence
    int seqIdx;

public:
    Level(int level, string file = " ");
    virtual char makeBlock() = 0;
    virtual bool dropped(bool clear) = 0;
    char makeBlockFile(); // makes block from file
    void populateSeq(); // CALL THIS FIRST, reads the file and populates the corresponding seq vectors
    void toggle();
    void toggleOn();
    void toggleOff(); //turns off the read variable
    void setSeed(int sd);
    void setScript(string scriptFile);
};
#endif
