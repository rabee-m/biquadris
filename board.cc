#include "board.h"
#include "cell.h"
#include <vector>
#include <iostream>
#include "level.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
using namespace std;

const int col_len = 11;
const int row_len = 18;

Board::Board() : player{0}, level{0}, id{0} {}

Score::Score() {
	score = 0;
	hi = 0;
}

int Score::getScore() {
	return score;
}

int Score::getHi() {
	return hi;
}

void Score::addScore(int add) {
	score += add;
	if (score > hi) {
		hi = score;
	}
}

void Score::resetScore() {
	score = 0;
}

Board::Board(int player, int level, int seed, string scriptFile,  bool blind)
       	: player{player}, level{level}, blind{blind}, seed{seed}, id{0}{
	for (int i = 0; i < row_len; ++i) {
		vector<Cell> curr_row;
		for (int j = 0; j < col_len; ++j) {
			Cell curr; //current cell we are adding
			//set coordinates of cell, i = row, j = col
			curr.setCoords(i, j);
			curr.setType(' ');
			curr.setId(-1);
			curr.setLvl(level);
			curr_row.emplace_back(curr); //add cell to the board row
		}
		theBoard.emplace_back(curr_row);
	}
	scr = Score();
	heavy = 0;
	if (level == 0) {
		lvl = std::make_unique<Level0>(scriptFile);
	} else if (level == 1) {
		lvl = std::make_unique<Level1>();
	} else if (level == 2) {
		lvl = std::make_unique<Level2>();
	} else if (level == 3) {
		lvl = std::make_unique<Level3>();
		heavy = 1;
	} else if (level == 4) {
		lvl = std::make_unique<Level4>();
		heavy = 1;
	}
	lvl->setSeed(seed);
	curr = NULL;
	next = NULL;
}

void Board::setRandom() {
	lvl->toggleOff();
}

void Board::setRead() {
	lvl->toggleOn();
}

void Board::setScript(string scriptFile) {
	lvl->setScript( scriptFile);
}

void Board::print() { 
	for (int i = 0; i < row_len; i++) {
		for (int j = 0; j < col_len; j++) {
			if (theBoard[i][j].getType() != ' ') {
				cout << theBoard[i][j].getType();
			} else {
				cout << ".";
			}
		}
		cout << endl;
	}
	cout << "---" << endl;
}

void Board::levelUp() {
	if (level < 4) {
		lvl.reset();
		level += 1;
		if (level == 0) {
                	lvl = std::make_unique<Level0>(scriptFile);
       	 	} else if (level == 1) {
         	        lvl = std::make_unique<Level1>();
        	} else if (level == 2) {
        	        lvl = std::make_unique<Level2>();
        	} else if (level == 3) {
                	lvl = std::make_unique<Level3>();
                	heavy = 1;
        	} else if (level == 4) {
                	lvl = std::make_unique<Level4>();
                	heavy = 1;
		}
		lvl->setSeed(seed);
        }
}

void Board::levelDown() {
        if (level > 0) {
		lvl.reset();
                level -= 1;
                if (level == 0) {
                	lvl = std::make_unique<Level0>(scriptFile);
                } else if (level == 1) {
                        lvl = std::make_unique<Level1>();
                } else if (level == 2) {
                        lvl = std::make_unique<Level2>();
                } else if (level == 3) {
                        lvl = std::make_unique<Level3>();
                        heavy = 1;
                } else if (level == 4) {
                        lvl = std::make_unique<Level4>();
                	heavy = 1;
		}
		lvl->setSeed(seed);
        }
}


void Board::setCell(int r, int c, int id, int lvl, char type) {
	theBoard[r][c].setType(type);
	theBoard[r][c].setId(id);
	theBoard[r][c].setLvl(lvl);
}

void Board::setId(int r, int c, int id) {
	theBoard[r][c].setId(id);
}

void Board::loadNext() {
	delete curr;
	curr = next;
	generateBlocks();
}

Cell *Board::getCell(int r, int c) {
	return &(theBoard[r][c]);
}

Block *Board::getNext() {
	return next;
}

Block *Board::getCurr() {
	return curr;
}

void Board::restart() {
	delete curr;
	delete next;
	for (int  r = 0; r < row_len ; ++r) {
		for (int c = 0; c < col_len; ++c) {
			setCell(r, c, -1, -1, ' ');
		}
	}
	scr.resetScore();
	id = 0;
}

void Board::generateBlocks() {
	char blk = lvl->makeBlock();
	id += 1;
	if (blk == 'I') {
		next = new iBlock(level, id, *this);
	} else if (blk == 'J') {
		next = new jBlock(level, id, *this);
        } else if (blk == 'O') {
		next = new oBlock(level, id, *this);
        } else if (blk == 'T') {
		next = new tBlock(level, id, *this);
        } else if (blk == 'S') {
		next = new sBlock(level, id, *this);
        } else if (blk == 'L') {
		next = new lBlock(level, id, *this);
	} else if (blk == 'Z') {
        	next = new zBlock(level, id, *this);
        }
}

void Board::setCurr(Block *c) {
	curr = c;
}

void Board::delNext() {
	delete next;
}

void Board::delCurr() {
	delete curr;
}

bool Board::insertBlock() {
	return curr->loadBlock();
}

void Board::force(char blk) {
	delNext();
	if (blk == 'I') {
                next = new iBlock(level, id, *this);
        } else if (blk == 'J') {
                next = new jBlock(level, id, *this);
        } else if (blk == 'O') {
                next = new oBlock(level, id, *this);
        } else if (blk == 'T') {
                next = new tBlock(level, id, *this);
        } else if (blk == 'S') {
                next = new sBlock(level, id, *this);
        } else if (blk == 'L') {
                next = new lBlock(level, id, *this);
        } else if (blk == 'Z') {
                next = new zBlock(level, id, *this);
        }
}

void Board::left() {
	curr->left();
	if (heavy == 1) {
		curr->down();
	} else if (heavy == 2) {
		curr->down();
		curr->down();
	}
}

void Board::right() {
	curr->right();
	if (heavy == 1) {
                curr->down();
        } else if (heavy == 2) {
                curr->down();
                curr->down();
        }
}

void Board::down() {
	curr->down();
}

void Board::clockwise() {
	curr->clockwise();
	if (heavy == 1) {
                curr->down();
        }
}

void Board::counterclockwise() {
	curr->counterclockwise();
	if (heavy == 1) {
                curr->down();
        }
}

void Board::drop() {
	curr->drop();
}

void Board::insertStar() {
	int clear;
	for (size_t i = 0; i < row_len; i++) {
		if (theBoard[i][5].getType() == ' ') {
			clear = i;
		} else {
			break;
		}
	}
	theBoard[clear][5].setType('*');
	id += 1;
	theBoard[clear][5].setId(id);
	theBoard[clear][5].setLvl(level);
	//check again here.
}

int Board::checkRows() {
	bool cleared = false;
	vector <cscore> rem;
	int rows = 0;
	for (size_t i = 0; i < theBoard.size(); i++) {
		bool full = true;
		for (size_t j = 0; j < theBoard[i].size(); j++) {
			if (theBoard[i][j].getType() == ' ') {
				full = false;	
			}
		}
		if (full) {
			cleared = true;
			rows += 1;
			for (size_t k = 0; k < theBoard[i].size(); k++) {
					bool exists = false;
					cscore temp = cscore{theBoard[i][k].getId(),
                                                theBoard[i][k].getLvl()};
					for (size_t l = 0; l < rem.size(); l++) {
						if (rem[l].id == temp.id) {
							exists = true;
						}
					}
					if (!exists) {
						rem.emplace_back(temp);
					}	
			}
			// Add score here.
			for (size_t k = i; k > 0; k--) {
				for (size_t l = 0; l < theBoard[k].size(); l++) {
					this->setCell(k, l, theBoard[k - 1][l].getId(),
							theBoard[k - 1][l].getLvl(),
							theBoard[k - 1][l].getType());
				}
			}
		}
	}
	if (rows > 0) {
		int add = 0;
		add += (level + rows) * (level + rows);
		for (size_t h = 0; h < rem.size(); h++) {
			bool found = false;
			for (size_t i = 0; i < theBoard.size(); i++) {
				for (size_t j = 0; j < theBoard[i].size(); j++) {
					if (theBoard[i][j].getId() == rem[h].id) {
						found = true;
					}
				}
			}
			if (!found) {
				add += rem[h].lvl + 1;
			}
		}
		scr.addScore(add);
	}
	if (level == 4) {
		if (lvl->dropped(cleared)) {
			insertStar();
		}
	}
	return rows;
}

Score Board::getScore() {
	return scr;
}

int Board::getLevelNum() {
	return level;
}

void Board::setHeavy(int _heavy) {
	heavy = _heavy;
}

void Board::makeLevelRandom() {
	lvl->toggleOff();
}

bool Board::isBlind() {
	return blind;
}

void Board::setBlind(bool _blind) {
	blind = _blind;
}
