#include "block.h"
#include <iostream>


const int MAX_ROWS = 18;
const int MAX_COLS = 11; // including reserve rows

Block::Block(char t, int l, int i, Board &b, vector<Posn> p) : type{t}, level{l}, id{i}, board{b}, points{p} 
{}

void Block::print(int r) {
	for (int i = 0; i < 4; i++) {
		bool found = false;
		for (size_t k = 0; k < points.size(); k++) {
			if (points[k].c == i && points[k].r == r) {
				found = true;
			}
		}
		if (found) {
			cout << this->type;
		} else {
			cout << " ";
		}
	}
}

// Checks if where we're loading the new block is already occuped with a block.
bool Block::checkLoad() {
	for (size_t i = 0; i < points.size(); i++) {
		if (board.getCell(points[i].r, points[i].c)->getType() != ' ') {
			return false;
		}
	}
	return true;
}

// Loads a new block into the board. Returns true if we can do it.
// Else, returns false and block is not loaded.
bool Block::loadBlock() {
	if (checkLoad()) {
		for (size_t i = 0; i < points.size(); i++) {
			board.setCell(points[i].r, points[i].c, id, level, type);
		}
	} else {
		return false;
	}
	return true;
}

// Functions for getting minimum and maximum coordinated occupied by a block.

int maxR(vector <Posn> points) {
        int max = points[0].r;
        for (size_t i = 0; i < points.size(); i++) {
                if (points[i].r > max) {
                        max = points[i].r;
                }
        }
        return max;
}

int maxC(vector <Posn> points) {
        int max = points[0].c;
        for (size_t i = 0; i < points.size(); i++) {
                if (points[i].c > max) {
                        max = points[i].c;
                }
        }
        return max;
}

int minR(vector <Posn> points) {
        int min = points[0].r;
        for (size_t i = 0; i < points.size(); i++) {
                if (points[i].r < min) {
                        min = points[i].r;
                }
        }
        return min;
}

int minC(vector <Posn> points) {
        int min = points[0].c;
        for (size_t i = 0; i < points.size(); i++) {
                if (points[i].c < min) {
                        min = points[i].c;
                }
        }
        return min;
}

bool Block::checkInsert(int r, int c) {
	if (r < 0 || r > MAX_ROWS - 1 || c < 0 || c > MAX_COLS - 1) {
		return false;
	}
	if (board.getCell(r, c)->getType() != ' ') {
		return false;
	}
	return true;
}

bool Block::left() {
	vector <Posn> temp = points;
        for (size_t i = 0; i < points.size(); i++) {
                temp[i].c -= 1;
        }
        for (size_t i = 0; i < points.size(); i++) {
                board.setCell(points[i].r, points[i].c, -1, level, ' ');
        }
        for (size_t i = 0; i < points.size(); i++) {
                if (!checkInsert(temp[i].r, temp[i].c)) {
                        for (size_t j = 0; j < points.size(); j++) {
                                board.setCell(points[j].r, points[j].c, id, level, type);
                        }
                        return false;
                }
        }
        points = temp;
        for (size_t i = 0; i < points.size(); i++) {
                board.setCell(points[i].r, points[i].c, id, level, type);
        }
        return true;
}

bool Block::right() {
	vector <Posn> temp = points;
        for (size_t i = 0; i < points.size(); i++) {
                temp[i].c += 1;
        }
        for (size_t i = 0; i < points.size(); i++) {
                board.setCell(points[i].r, points[i].c, -1, level, ' ');
        }
        for (size_t i = 0; i < points.size(); i++) {
                if (!checkInsert(temp[i].r, temp[i].c)) {
                        for (size_t j = 0; j < points.size(); j++) {
                                board.setCell(points[j].r, points[j].c, id, level, type);
                        }
                        return false;
                }
        }

        points = temp;
        for (size_t i = 0; i < points.size(); i++) {
                board.setCell(points[i].r, points[i].c, id, level, type);
        }
        return true;
}


bool Block::down() {
	vector <Posn> temp = points;
	for (size_t i = 0; i < points.size(); i++) {
		temp[i].r += 1;
	}
	for (size_t i = 0; i < points.size(); i++) {
		board.setCell(points[i].r, points[i].c, -1, level, ' ');
	}
	for (size_t i = 0; i < points.size(); i++) {
                if (!checkInsert(temp[i].r, temp[i].c)) {
                        for (size_t j = 0; j < points.size(); j++) {
                                board.setCell(points[j].r, points[j].c, id, level, type);
			}
                        return false;
                }
        }

	points = temp;
	for (size_t i = 0; i < points.size(); i++) {
		board.setCell(points[i].r, points[i].c, id, level, type);
	}
	return true;
}

void Block::drop() {
	while (true) {
		if (!down()) {
			break;
		}
	}
}	

// Rotates clockwise 1 time and adds it to the board.
bool Block::clockwise() {
	vector <Posn> temp = this->points;
	Posn p = {maxR(points), minC(points)};
	for (size_t i = 0; i < points.size(); i++) {
		points[i].c -= maxC(temp) - minC(temp);
		Posn newCoord = {(points[i].c - p.c) + p.r, -(points[i].r - p.r) + p.c};
		points[i] = newCoord;
	}
	// Clearing where the unrotated block was.
	for (size_t i = 0; i < points.size(); i++) {
		board.setCell(temp[i].r, temp[i].c, -1, level, ' ');
	}
	for (size_t i = 0; i < points.size(); i++) {
		if (!checkInsert(points[i].r, points[i].c)) {
			points = temp;
			for (size_t j = 0; j < points.size(); j++) {
				board.setCell(points[j].r, points[j].c, id, level, type);
			}
			return false;
		}
	}
	for (size_t i = 0; i < points.size(); i++) {
		board.setCell(points[i].r, points[i].c, id, level, type);
	}
	return true;
}

bool Block::counterclockwise() {
	for (int i = 0; i < 3; i++) {
		if (!clockwise()) {
			return false;
		}
	}
	return true;
}


char Block::getType() {
	return type;
}

/* Constructors for all the blocks. */

iBlock::iBlock(int l, int i, Board &b):
	Block('I', l, i, b, vector <Posn> {Posn{3,0}, Posn{3,1}, Posn{3,2}, Posn{3,3}})
{}

jBlock::jBlock(int l, int i, Board &b):
    Block('J', l, i, b, vector <Posn> {Posn{2,0}, Posn{3,0}, Posn{3,1}, Posn{3,2}})
{}

lBlock::lBlock(int l, int i, Board &b):
    Block('L', l, i, b, vector <Posn> {Posn{3,0}, Posn{3,1}, Posn{3,2}, Posn{2,2}})
{}

oBlock::oBlock(int l, int i, Board &b):
    Block('O', l, i, b, vector <Posn> {Posn{3,0}, Posn{2,0}, Posn{2,1}, Posn{3,1}})
{}

sBlock::sBlock(int l, int i, Board &b):
    Block('S', l, i, b, vector <Posn> {Posn{3,0}, Posn{3,1}, Posn{2,1}, Posn{2,2}})
{}

zBlock::zBlock(int l, int i, Board &b):
    Block('Z', l, i, b, vector <Posn> {Posn{2,0}, Posn{2,1}, Posn{3,1}, Posn{3,2}})
{}

tBlock::tBlock(int l, int i, Board &b):
    Block('T', l, i, b, vector <Posn> {Posn{2,0}, Posn{2,1}, Posn{2,2}, Posn{3,1}})
{}
