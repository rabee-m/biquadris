#ifndef LEVEL3_H
#define LEVEL3_H

#include "level.h"

class Level3 : public Level {
	int calls;
	public:
		Level3();
		char makeBlock() override;
		bool dropped(bool clear) override;
};
#endif
