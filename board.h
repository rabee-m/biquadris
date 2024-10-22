#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <memory>
#include "cell.h"
#include "block.h"
#include <memory>
#include "level.h"
//#include "level0.h"
using namespace std;

class Level;
class Level0;
class Block;

struct cscore {
	int id;
	int lvl;
};

class Score {
	int score;
	int hi;

	public:
		Score();
		int getScore();
		int getHi();
		void addScore(int add);
		void resetScore();
};

class Board {
	std::vector<std::vector<Cell>> theBoard;
	int player; //either 1 or 2 repersenting what player board is for
	int level;
	bool blind;
	int seed;
	int id;
	int heavy;
	string scriptFile;
	unique_ptr <Level> lvl;
	Block *next;
	Block *curr;
	Score scr;

	public:
	       	Board();
		Board(int player, int level, int seed, string scriptFile, bool blind=false);
		Cell *getCell(int r, int c);
		Score getScore();
		void print();
		void setCell(int r, int c,int id, int lvl, char type);
		void setId(int r, int c, int id);
		int checkRows();
		void generateBlocks();
		Block *getNext();
		Block *getCurr();
		void setCurr(Block *c);
		bool insertBlock();
		void down();
		void left();
		void right();
		void drop();
		void clockwise();
		void counterclockwise();
		void delCurr();
		void delNext();
		void loadNext();
		int getLevelNum();
		void insertStar();
		void makeLevelRandom();
		bool isBlind();
		void setBlind(bool _blind);
		void setHeavy(int _heavy);
		void force(char blk);
		void restart();
		void levelUp();
		void levelDown();
		void setRead();
	       	void setRandom();	
		void setScript(string script);
	
};
#endif
