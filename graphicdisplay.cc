#include "window.h"
#include "graphicdisplay.h"
#include "board.h"
#include <string>
const int cell_width = 25;
const int cell_height = 25;



GraphicDisplay::GraphicDisplay(bool graphicsOn)
	:graphicsOn{graphicsOn} {
	if (graphicsOn) {
		xw = new Xwindow{}; 
	} else {
		xw = nullptr; 
	}
}

GraphicDisplay::~GraphicDisplay() {
	delete xw;
}


void GraphicDisplay::printLevels(int playerOneLevel, int playerTwoLevel) {
	string playerOneText = "Level........";
	playerOneText += to_string(playerOneLevel);
	
	string playerTwoText = "Level........";
	playerTwoText += to_string(playerTwoLevel);

	xw->drawString(3 * cell_width, 2 * cell_height, playerOneText);
	xw->drawString(16 * cell_width, 2 * cell_height, playerTwoText);
}


void GraphicDisplay::printScores(Score s1, Score s2) {
	string playerOneText = "Score........";
	playerOneText += s1.getScore();

	string playerTwoText = "Score........";
	playerTwoText += s2.getScore();

	xw->drawString(3 * cell_width, 4 * cell_height, playerOneText);
	xw->drawString(16 * cell_width, 4 * cell_height, playerTwoText);
}

void GraphicDisplay::initGraphics(Board &p1, Board &p2) {
        printLevels(p1.getLevelNum(), p2.getLevelNum());
	printScores(p1.getScore(), p2.getScore());
		for (int r = 0; r < 18; ++r) {
			xw->fillRectangle(11 * cell_width, r *cell_height,
					cell_width, cell_height, Xwindow::Black);
			xw->fillRectangle(12 * cell_width, r * cell_height,
					cell_width, cell_height, Xwindow::Black);
		}
		
        }

void GraphicDisplay::updatePlayerOneGraphics(Board &p1, Board &p2) {
        printLevels(p1.getLevelNum(), p2.getLevelNum());
	printScores(p1.getScore(), p2.getScore());
        for (int r = 0; r < 18; ++r) {
                //print player1 board line
                for (int c = 0; c < 11; ++c) {
                        xw->fillRectangle(c * cell_width, r * cell_height,
                                        cell_width, cell_height,
                                       getCellColour(p1.getCell(r,c)->getType()));
		}
	}
}

void GraphicDisplay::updatePlayerTwoGraphics(Board &p1, Board &p2) {
        for (int r = 0; r < 18; ++r) {
                //print player1 board line
                for (int c = 0; c < 11; ++c) {
                        xw->fillRectangle( (c + 13) * cell_width, r * cell_height,
                                        cell_width, cell_height,
                                       getCellColour(p2.getCell(r,c)->getType()));
                }
        }
}


int GraphicDisplay::getCellColour(char type) {
	if (type == 'O') {
		return Xwindow::Blue;
	} else if (type == ' ') {
		return Xwindow::White;
	} else if (type == 'I') {
		return Xwindow::Pink;
	} else if (type == 'J') {
		return Xwindow::Red;
	} else if (type == 'S') {
		return Xwindow::Purple;
	} else if (type == 'T') {
		return Xwindow::Yellow;
	} else if (type == 'L') {
		return Xwindow::Orange;
	} else if (type == 'Z') {
		return Xwindow::Green;
	} else {
		//star block
		return Xwindow::Coral;
	}
}
