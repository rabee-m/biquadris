#ifndef LEVEL0_H
#define LEVEL0_H

#include "level.h"
#include <string>
using namespace std;

class Level0 : public Level {
public:
    Level0(string file);
    char makeBlock() override;
    bool dropped(bool clear) override;
};
#endif
