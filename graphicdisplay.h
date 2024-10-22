#include "window.h"
#include <memory>
#include "board.h"

class Board;

class GraphicDisplay {
	bool graphicsOn;
	Xwindow *xw;
	//std::unique_ptr<Xwindow> xw;
	public:
	GraphicDisplay(bool graphicsOn);
	~GraphicDisplay();
	void initGraphics(Board &p1, Board &p2);
	int getCellColour(char type);
	void updatePlayerOneGraphics(Board &p1, Board &p2);
	void updatePlayerTwoGraphics(Board &p1, Board &p2);
	void printLevels(int playerOneLevel, int playerTwoLevel);
	void printScores(Score s1, Score s2);
};
