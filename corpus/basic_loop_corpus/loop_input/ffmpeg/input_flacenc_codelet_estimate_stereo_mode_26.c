#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int best;
uint64_t score[4];

void init_vars() {
    // Initialize scalar variables
    i = 0;
    best = 0;

    // Initialize score array with non-uniform values to allow meaningful comparison in loop
    score[0] = 100;
    score[1] = 200;
    score[2] = 50;
    score[3] = 75;
}