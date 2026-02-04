#include <stdio.h>
#include <inttypes.h>

struct aa_move {
    int move;
    int target[4];
};

struct aa_move attacks[361];
int move;
int k;

void init_vars() {
    // Initialize the attacks array with valid data
    for (int i = 0; i < 361; i++) {
        attacks[i].move = (i % 2 == 0) ? (i + 1) : 0;  // Half of them have move == 0, others non-zero
        for (int j = 0; j < 4; j++) {
            attacks[i].target[j] = i * 4 + j;
        }
    }

    // Set 'move' to a value that will cause early break (match at first element with same move)
    move = 1;  // This will match attacks[0].move if it's 1, otherwise loop continues
}