#include "textdisplay.h"
#include "board.h"
#include <iostream>

//potentially add to class itself
const string DIVIDER = "      "; //divides p1 and p2 boards


void TextDisplay::levelPrint(int p1_lvl, int p2_lvl) {
	cout << "Level:    " << p1_lvl;
	cout << DIVIDER;
	cout << "Level:    " << p2_lvl;
	cout << endl;
}

void TextDisplay::scorePrint(Score s1, Score s2) {
        cout << "Score:    " << s1.getScore();
        cout << DIVIDER;
        cout << "Score:    " << s2.getScore();
	cout << endl;
}

void TextDisplay::boardsPrint(Board &p1, Board &p2) {
	for (int r = 0; r < 18; ++r) {
		//print player1 board line
		for (int c = 0; c < 11; ++c) {
			cout << (p1.getCell(r, c))->getType();
		}
		cout << DIVIDER;
		//print player2 board line
		for (int c = 0; c < 11; ++c) {
			cout << (p2.getCell(r,c))->getType();
		}
		cout << endl;
	}
}

void TextDisplay::gameOver(int player) {
	cout << "Game over! Player " << player << " has lost!" << endl;
}

void TextDisplay::nextPrint(Board &p1, Board &p2) {
	//print ----- line for player 1 board
	for (int c = 0; c < 11; ++c) {
		cout << "-";
	}
	cout << DIVIDER;
	//print ----- line for player 2 board
	for (int c = 0; c < 11; ++c) {
		cout << "-";
	}
	cout << DIVIDER << DIVIDER;
	cout << endl;

	//print next word for both players
	cout << "Next:" << DIVIDER << DIVIDER << "Next:" <<endl;
	
	//print nextBlock for player1 and player2
	for (int i = 1; i <= 3; i++) {
		(p1.getNext())->print(i);
       		cout << DIVIDER << DIVIDER << " ";
		(p2.getNext())->print(i);
		cout << endl;
	}
}

void TextDisplay::printGame(Board &p1, Board &p2) {
	levelPrint(p1.getLevelNum(), p2.getLevelNum());
	scorePrint(p1.getScore(), p2.getScore()); //placeholder since we don't have getScore func
	if (p1.isBlind()) {
		blindPlayerOne(p1, p2);
	} else if (p2.isBlind()) {
		blindPlayerTwo(p1, p2);
	} else {
		boardsPrint(p1, p2);
	}
	nextPrint(p1, p2);
}

void TextDisplay::blindPlayerTwo(Board &p1, Board &p2) {
        for (int r = 0; r < 18; ++r) {
                //print player1 board line
                for (int c = 0; c < 11; ++c) {
                        cout << (p1.getCell(r, c))->getType();
                }
                cout << DIVIDER;
                //print player2 board line
                for (int c = 0; c < 11; ++c) {
			if (c >= 2 && c <= 8 && r >= 2 && r <= 11) {
			       //blinded sections of the board
				cout << "?";
			} else {	
                        	cout << (p2.getCell(r,c))->getType();
			}
                }
                cout << endl;
        }
}

void TextDisplay::blindPlayerOne(Board &p1, Board &p2) {
        for (int r = 0; r < 18; ++r) {
                //print player1 board line
                for (int c = 0; c < 11; ++c) {
			if (c >= 2 && c <= 8 && r >= 2 && r<= 11) {
				//blinded sections of the board
				cout << "?";
			} else {
                        	cout << (p1.getCell(r, c))->getType();
			}
                }
                cout << DIVIDER;
                //print player2 board line
                for (int c = 0; c < 11; ++c) {
                        if (c >= 2 && c <= 8 && r >= 2 && r <= 11) {
                               //blinded sections of the board
                                cout << "?";
                        } else {
                                cout << (p2.getCell(r,c))->getType();
                        }
                }
                cout << endl;
        }
}
