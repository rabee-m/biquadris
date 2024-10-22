#ifndef LEVEL2_H
#define LEVEL2_H

#include "level.h"

class Level2 : public Level {
	int calls; // Stores the number of calls, as the seed resets with each makeBlock call.
	public:
		Level2();
		char makeBlock() override;
		bool dropped(bool clear) override;
};
#endif

