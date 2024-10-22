#include "level2.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

static const int z_prob = 1; // probabilities of the blocks
static const int s_prob = 2;
static const int i_prob = 3;
static const int j_prob = 4;
static const int l_prob = 5;
static const int o_prob = 6;
static const int t_prob = 7;

Level2::Level2() : Level{2} {
	calls = 0;
}

bool Level2::dropped(bool dropped) {
	return true;
}

char Level2::makeBlock() {
	srand(1);                  // sets the seed, default = 1
        int num = 0; 
	for (int i = 0; i < calls; i++) {
		num = rand();
	}
	num = rand() % 7 + 1;
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
        } else {
            return 'T';
        }
}


