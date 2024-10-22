#include "level0.h"

Level0::Level0(string file) : Level(0, file) {}

char Level0::makeBlock() {
    return makeBlockFile();
}

bool Level0::dropped(bool clear) {
	return true;
}
