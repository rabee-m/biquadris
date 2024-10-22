#ifndef LEVEL4_H
#define LEVEL4_H

#include "level.h"

class Level4 : public Level {
	int calls; // Stores the number of calls, as the seed resets with each makeBlock call.
	int turns;
	public:
		Level4();
		char makeBlock() override;
		bool dropped(bool clear) override;
};
#endif
