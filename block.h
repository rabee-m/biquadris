#ifndef BLOCK_H
#define BLOCK_H
#include "board.h"
#include "cell.h"
#include <string>
#include <vector>
using namespace std;

class Board;

struct Posn { // position on the board
    int r; // row
    int c; // column
};

class Block {
protected:
    char type; // type of block
    int level; // for level generation
    int id;
    Board &board; // reference to the board.
    vector<Posn> points; // holds the list of points that the block is occupying

public:
    Block(char t, int l, int id, Board &b, vector<Posn> p); // type, level, board
    void drop(); // can be done by using the move function above
    void print(int r);
    bool clockwise();
    bool loadBlock();
    bool checkLoad();
    bool checkInsert(int r, int c);
    bool down();
    bool right();
    bool left();
    bool counterclockwise();
    char getType();
};


class iBlock : public Block {
	public:
		iBlock(int l, int i, Board &b);
};

class jBlock : public Block {
	public:
		jBlock(int l, int i, Board &b);
};

class lBlock : public Block {
	public:
		lBlock(int l, int i, Board &b);
};

class oBlock : public Block {
	public:
		oBlock(int l, int i, Board &b);
};

class sBlock : public Block {
	public:
		sBlock(int l, int i, Board &b);
};

class zBlock : public Block {
	public: 
		zBlock(int l, int i, Board &b);
};

class tBlock : public Block {
	public:
		tBlock(int l, int i, Board &b);
};

class dotBlock : public Block {
	public:
		dotBlock(int l, int i, Board &b);
};

#endif
