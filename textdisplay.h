#ifndef _TEXTDISPLAY_H_
#define _TEXTDISPLAY_H_

#include "board.h"

class TextDisplay {
	public:
		void levelPrint(int p1_lvl, int p2_lvl); // prints level line of display
		void scorePrint(Score s1, Score s2); //prints score line of display
		void boardsPrint(Board &p1, Board &p2); //prints boards of display
		void nextPrint(Board &p1, Board &p2); //prints next blocks
		void printGame(Board &p1, Board &p2); //wrapper that wraps all print functions
		void blindPlayerOne(Board &p1, Board &p2); //prints boards w/ p1 board blinded
		void blindPlayerTwo(Board &p1, Board &p2); //prints boards w/ p2 board blinded
		void gameOver(int player);
};

#endif
