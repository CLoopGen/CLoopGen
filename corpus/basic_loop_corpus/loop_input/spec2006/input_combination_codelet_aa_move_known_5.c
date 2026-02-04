#include <stdio.h>
#include <inttypes.h>

struct aa_move {
    int move;
    int target[4];
};

#define ARRAY_SIZE (19 * 19)

struct aa_move attacks[ARRAY_SIZE];
int move;
int k;

void init_vars() {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        attacks[i].move = (i == ARRAY_SIZE - 1) ? 0 : (i + 1);
        for (int j = 0; j < 4; j++) {
            attacks[i].target[j] = i * 4 + j;
        }
    }
    move = 0;
    k = 0;
}