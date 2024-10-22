#include "level3.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

static const int z_prob = 2; // probabilities of the blocks
static const int s_prob = 4;
static const int i_prob = 5;
static const int j_prob = 6;
static const int l_prob = 7;
static const int o_prob = 8;
static const int t_prob = 9;

Level3::Level3() : Level{3} {
	calls = 0;
}

bool Level3::dropped(bool clear) {
	return true;
}

char Level3::makeBlock() {
    if (!read) {
        srand(1);                  // sets the seed, default = 1
        int num = 0; 
	for (int i = 0; i < calls; i++) {
		num = rand();
	}
	num = rand() % 9 + 1;
	calls += 1;
        if (num <= z_prob) {
            return 'Z'; // add block generation here
        } else if (num <= s_prob) {
            return 'S';
        } else if (num <= i_prob) {
            return 'I';
        } else if (num <= j_prob) {
            return 'J';
        } else if (num <= l_prob) {
            return 'L';
        } else if (num <= o_prob) {
            return 'O';
        } else if (num <= t_prob) {
            return 'T';
        }
    }
    return makeBlockFile();
}


