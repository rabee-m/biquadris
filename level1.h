#ifndef LEVEL1_H
#define LEVEL1_H


#include "level.h"


class Level1 : public Level {
	int calls;
    public:
        Level1();
        char makeBlock() override;
	bool dropped(bool clear) override;
};
#endif
