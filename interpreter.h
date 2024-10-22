#ifndef INTERPRETER_H
#define INTERPRETER_H
#include <vector>
#include <string>
#include "board.h"

class BlockGame;

using namespace std;

class Interpreter {
	BlockGame *biquadris; //pointer to game
	vector <string> commands; //list of all valid commands
	
	public:
	Interpreter(BlockGame *biquadris);
	bool executeCommand(Board &b, string cmd); //executes given string cmd
};
#endif
