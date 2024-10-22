#include "level.h"
#include <fstream>
#include <iostream>

void Level::populateSeq() {
        char block;
        ifstream infile {file};
        while(true) {
                infile >> block;
                if (infile.fail()) {
                        break;
                }
                block = toupper(block); // converts chars to uppercase
                seq.emplace_back(block);
        }
}

Level::Level(int lvl, string file): lvl{lvl}, seed{1}, file{file}, seqIdx{0} {
    	if (file != " ") {
        	read = true;
		populateSeq();
    	} else {
        	read = false;
    	}
}

char Level::makeBlockFile() {
    char block;
    int last = seq.size() - 1;
    block = seq[seqIdx];
    if (seqIdx == last) {
	    seqIdx = 0;
    } else {
    	++seqIdx;
    }
    return block;
}

void Level::toggle() {
	read = !read;
}

void Level::setSeed(int sd) {
	seed = sd;
	cout << "SEED IS: " << sd << endl;
}

void Level::toggleOff() {
	read = false;
}

void Level::toggleOn() {
	read = true;
}

void Level::setScript(string scriptFile) {
	file = scriptFile;
	populateSeq();
}
