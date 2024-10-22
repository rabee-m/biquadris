#include "level1.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

// probabilities of the blocks
static const int z_prob = 1;
static const int s_prob = 2;
static const int i_prob = 4;
static const int j_prob = 6;
static const int l_prob = 8;
static const int o_prob = 10;
static const int t_prob = 12;

Level1::Level1() : Level{1} {
	calls = 0;
}

bool Level1::dropped(bool clear) {
	return true;
}

char Level1::makeBlock() {
        srand(1);	// sets the seed, default = 1
	int num = 0;
	for (int i = 0; i < calls; i++) {
		num = rand();
	}
        num = rand() % 12 + 1; // random num between 1-12
	cout << num << endl;
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
