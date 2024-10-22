#include "blockgame.h"
#include "board.h"
#include "level.h"
#include "level0.h"
#include <string>
#include <iostream>
#include "interpreter.h"
#include "textdisplay.h"

BlockGame::BlockGame(bool graphicsOn, int seed, string scriptFile1,
		string scriptFile2, int startLevel)
	: graphicsOn{graphicsOn}, seed{seed}, scriptFile1{scriptFile1},
	scriptFile2{scriptFile2}, level{startLevel}, i{this},
	gd{GraphicDisplay{graphicsOn}}
{
	this->p1 = Board(1, level, seed, scriptFile1);
	this->p2 = Board(2, level, seed, scriptFile2);
	gameOver = false;
	i = Interpreter(this);
	td = TextDisplay();
	current_player = 1; //player 1 starts
}

void BlockGame::turn() {
	string cmd = "";
	string special_effect = ""; //for special effects
	char force_block = ' '; //block we are forcing
	//player 1's turn
	p1.loadNext();
	if (!p1.insertBlock()) {
		gameOver = true;
		td.gameOver(1);
		return;
	}
	//player one print next block
	current_player = 1;
	printBlockGame();
	while (cin >> cmd) {
		if(!i.executeCommand(p1,cmd)) {
			break;
		}
	}
	//turn off p1's special effects
	p1.setBlind(false);
	if (p2.getLevelNum() >= 3) {
		//level 3 and level 4 have a default heavy of 1
		p2.setHeavy(1);
	} else {
		//all other levels have default heavy of 0
		p2.setHeavy(0);
	}

	//check if p1 cleared more than 2 rows and can  use a 
	//special effect
	if (p1.checkRows() >= 2) {
		cout << "enter a special effect: ";
		cin >> special_effect;
		cout << endl;
		if (special_effect == "blind") {
			p2.setBlind(true);
		} else if (special_effect == "heavy") {
			p2.setHeavy(2);
		} else if (special_effect == "force") {
			cin >> force_block;
                      	cout << endl;			                       
		       	p2.force(force_block);
		}
	}
	p1.checkRows(); //check for board filled
	//player 2's turn
        p2.loadNext();
	if (!p2.insertBlock()) {
		gameOver = true;
		td.gameOver(2);
		return;
	}
        //player two print next block
	current_player = 2;
	printBlockGame();
        while (cin >> cmd) {
                if(!i.executeCommand(p2,cmd)) {
                        break;
                }
        }
	//turn off p2's special efects
	p2.setBlind(false);
	if (p2.getLevelNum() >= 3) {
		//level 3 and level 4 have a default heavy of 1
		p2.setHeavy(1);
	} else {
		//all other levels have default heavy of 0
		p2.setHeavy(0);
	}
	//check if p2 cleared more than 2 rows and can use a special
	//effect
	if (p2.checkRows() >= 2) {
		cout << "enter a special effect: ";
		cin >> special_effect;
		if (special_effect == "blind") {
			p1.setBlind(true);
		} else if (special_effect == "heavy") {
			p1.setHeavy(2);
		} else if (special_effect == "force") {
			cin >> force_block;
			cout << endl;
			p1.force(force_block);
		}
		cout << endl;
	}
        p2.checkRows(); //check for board filled
}

void BlockGame::printBlockGame() {
	td.printGame(p1, p2);
	if (graphicsOn) {
		updateGraphics();
	}
}

void BlockGame::restart() {
	p1.restart();
	p2.restart();
	play();
}

void BlockGame::play() {
	//generate the first blocks for each board
	p1.generateBlocks();
	p2.generateBlocks();
	if (graphicsOn) {
		//intialize graphics display
		gd.initGraphics(p1, p2);
	}
	while(!gameOver) {
		turn();
	}
	//turn off both player's blind special effect
	//in case
	p1.setBlind(false);
	p2.setBlind(false);
	//delete blocks
		p1.delCurr();
		p1.delNext();
		p2.delCurr();
		p2.delNext();

}

void BlockGame::switchScriptFile(string filename) {
	if (current_player == 1) {
		scriptFile1 = filename;
	} else if (current_player == 2) {
		scriptFile2 = filename;
	}
}

void BlockGame::makeLevelRandom() {
	if (current_player == 1) {
		p1.makeLevelRandom();
	} else if (current_player == 2) {
		p2.makeLevelRandom();
	}
}

bool BlockGame::isGraphicsOn() {
	return graphicsOn;
}

void BlockGame::updateGraphics() {
	if (current_player == 1) {
		gd.updatePlayerOneGraphics(p1,p2);
	} else if (current_player == 2) {
		gd.updatePlayerTwoGraphics(p1,p2);
	}
}
