#include "interpreter.h"
#include <string>
#include <vector>
#include <iostream>
#include "board.h"
#include "blockgame.h"
#include <fstream>

Interpreter::Interpreter(BlockGame *biquadris)
	:biquadris{biquadris}
{
	commands.emplace_back("left");
	commands.emplace_back("right");
	commands.emplace_back("down");
	commands.emplace_back("clockwise");
	commands.emplace_back("counterclockwise");
	commands.emplace_back("drop");
	commands.emplace_back("levelup");
        commands.emplace_back("leveldown");
        commands.emplace_back("norandom");
        commands.emplace_back("random");
        commands.emplace_back("sequence");
        commands.emplace_back("I");
        commands.emplace_back("J");
        commands.emplace_back("L");
	commands.emplace_back("O");
	commands.emplace_back("T");
	commands.emplace_back("S");
        commands.emplace_back("restart");
	commands.emplace_back("hint");
}


bool Interpreter::executeCommand(Board &b, string cmd) {
	int multiplier = 1;
	//check if first character in cmd is a number
	if (cmd.length() == 0) {
		cerr << "no command issued" << endl;
	}
	if (cmd.at(0) >= '0' && cmd.at(0) <= '9') {
		if (cmd.at(1) >= '0' && cmd.at(1) <= '9') {
			if (cmd.length() == 1) {
				cerr << "multiplier given, no command" << endl;
			}
			multiplier = stoi(cmd.substr(0, 2)); //double digit multiplier
			cmd = cmd.substr(2); //removes first two characters
		} else {
			multiplier = cmd.at(0) - '0'; //single digit multiplier
		//remove multiplier from cmd string
		if (cmd.length() == 1) {
			//check if only multipler given
			cerr << "multiplier given, but no command" << endl;
		}
		cmd = cmd.substr(1); //removes first character
		}
	}
	//determine command given
	string commandGiven = cmd;
	
	bool commandFound = false; //used for ambigious commands
	for (auto c: commands) {
		if (cmd.length() > c.length()) {
			//command is too big, skip this
			continue;
		}
		if (cmd == c.substr(0, cmd.length())) {
			if (commandFound) {
				cerr << "ambigious command" << endl;
				break;
				//possibly break out of loop
			}
			commandGiven = c;
			commandFound = true;
		}
	}
	if (!commandFound) { //command not found
		cerr << "invalid command" << endl;
	}
	//execute command
	if (commandGiven == "left") {
		for (int i = 0; i < multiplier; ++i) {
			b.left();
			//if (biquadris->isGraphicsOn()) {
			//	biquadris->updateGraphics();
			//}
			biquadris->printBlockGame();
		}
		/*
			for (int i = 0; i < multiplier; ++i) {
			(player.getCurrBlock)->left();
			}
			break;
			*/
	} else if (commandGiven == "right") {
		for (int i = 0; i < multiplier; ++i) {
			b.right();
                        //if (biquadris->isGraphicsOn()) {
                          //      biquadris->updateGraphics();
                        //}
			biquadris->printBlockGame();
		}
		/*
			for (int i =0; i < multiplier; ++i) {
			(player.getCurrBlock)->right();
			}
			break;
			*/
	} else if (commandGiven == "down") {
		for (int i = 0; i < multiplier; ++i) {
			b.down();
                        //if (biquadris->isGraphicsOn()) {
                          //      biquadris->updateGraphics();
                        //}
			biquadris->printBlockGame();
		}
		/*
                        for (int i =0; i < multiplier; ++i) {
                        (player.getCurrBlock)->down();
                        }
			break;
			*/
	} else if (commandGiven == "clockwise") {
		for (int i = 0; i < multiplier; ++i) {
			b.clockwise();
                        //if (biquadris->isGraphicsOn()) {
                          //      biquadris->updateGraphics();
                        //}
			biquadris->printBlockGame();
		}
		/*
		case clockwise:
                        for (int i =0; i < multiplier; ++i) {
                        (player.getCurrBlock)->clockwise();
                        }
			break;
			*/
	} else if (commandGiven == "counterclockwise") {
		for (int i = 0; i < multiplier; ++i) {
			b.counterclockwise();
                        //if (biquadris->isGraphicsOn()) {
                          //      biquadris->updateGraphics();
                        //}
			biquadris->printBlockGame();
		}
		//b.print();
		/*
		case counterclockwise:
                        for (int i =0; i < multiplier; ++i) {
                        (player.getCurrBlock)->counterclockwise();
                        }
			break;
			*/
	} else if (commandGiven == "drop") {
		for (int i = 0; i < multiplier; ++i) {
			b.drop();
                        //if (biquadris->isGraphicsOn()) {
                          //      biquadris->updateGraphics();
                        //}
			biquadris->printBlockGame();
		}
		//b.print();
		return false;
	} else if (commandGiven == "sequence") {
		string filename;
		cin >> filename;
		ifstream fileStream {filename};
		string fileCommand;

		while (fileStream >> fileCommand) {
			if (!executeCommand(b, fileCommand)) {
				break;
			}
		}
		return false;
	} else if (commandGiven == "norandom") {
		string filename;
		cin >> filename;
		b.setRead();
		b.setScript(filename);
	} else if (commandGiven == "random") {
		b.setRandom();
	} else if (commandGiven == "hint") {
		cout << "Hint: The next block is a ";
		cout << (b.getNext())->getType() << "-block!" << endl;
		cout << "Good Luck :)" << endl;
	} else if (commandGiven == "restart") {
		biquadris->restart();
		return false;
	} else if (commandGiven == "levelup") {
		b.levelUp();
		biquadris->printBlockGame();
	} else if (commandGiven == "leveldown") {
		b.levelDown();
		biquadris->printBlockGame();
	}
	return true;
}
