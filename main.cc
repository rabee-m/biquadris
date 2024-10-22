#include "board.h"
#include "block.h"
#include "level.h"
#include "level1.h"
#include <iostream>
#include "level0.h"
#include <memory>
#include "blockgame.h"
#include <cstring>
#include <time.h>

int main(int argc, char *argv[]) {
        //default values
        bool graphicsOn = true;
        int seed = time(0);
        string scriptFile1 = "sequence1.txt";
        string scriptFile2 = "sequence2.txt";
        int levelStart = 0;
        //loop through command line args and change default options for
        //game
        for (int i = 0; i < argc; ++i) {
		string curr_arg{argv[i]};
		if (curr_arg == "-text") {
                        graphicsOn= false;
		} else if (curr_arg == "-seed") {
                        seed = stoi(argv[i + 1]);
		} else if (curr_arg == "-scriptfile1") {
                        scriptFile1 = argv[i + 1];
		} else if (curr_arg == "-scriptfile2") {
                        scriptFile2 = argv[i + 1];
		} else if (curr_arg == "-startlevel") {
                        levelStart = stoi(argv[i + 1]);
                }
        }
        //intialize the blockGame class
	BlockGame game {graphicsOn, seed, scriptFile1, scriptFile2, levelStart};
	game.play();

}
