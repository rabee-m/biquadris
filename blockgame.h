#ifndef BLOCKGAME_H_
#define BLOCKGAME_H_
#include "board.h"
#include "interpreter.h"
#include "textdisplay.h"
#include "graphicdisplay.h"

class BlockGame {
	bool graphicsOn;
	int seed;
	string scriptFile1;
	string scriptFile2;
	int level;
	Board p1;
	Board p2;
	bool gameOver;
	Interpreter i;
	TextDisplay td;
	GraphicDisplay gd;
	int current_player;
	public:
		BlockGame(bool graphicsOn, int seed, string scriptFile1,
				string scriptFile2, int startlevel);
		void play();
		void turn();
		void printBlockGame();
		void updateGraphics();
		void switchScriptFile(std::string filename);
		void makeLevelRandom();
		bool isGraphicsOn();
		void restart();
};
#endif
