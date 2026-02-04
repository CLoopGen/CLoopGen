#include <stdio.h>
#include <inttypes.h>

struct aa_move {
    int move;
    int target[4];
};

struct aa_move attacks[361];
int target;
int k;
int r;

void init_vars() {
    for (int i = 0; i < 361; i++) {
        attacks[i].move = i + 1;
        for (int j = 0; j < 4; j++) {
            attacks[i].target[j] = (i * 4 + j) % 100;
        }
    }
    target = 50;
    k = 100;
    r = 0;
}