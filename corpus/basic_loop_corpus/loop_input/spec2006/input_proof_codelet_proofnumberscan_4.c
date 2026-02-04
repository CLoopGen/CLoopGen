#include <stdio.h>
#include <inttypes.h>

int rootlosers[300];
int islegal[512];
int nodesspent[512];
int i;
int l;
int num_moves;
int leastlooked;
int leastlooked_l;
int leastlooked_i;

void init_vars() {
    num_moves = 512;
    leastlooked = 1000000;
    l = 0;
    leastlooked_l = 0;
    leastlooked_i = 0;

    for (int idx = 0; idx < 512; idx++) {
        nodesspent[idx] = 1000 + idx;
        islegal[idx] = (idx % 3 != 0);
    }

    for (int idx = 0; idx < 300; idx++) {
        rootlosers[idx] = (idx % 7 == 0);
    }
}