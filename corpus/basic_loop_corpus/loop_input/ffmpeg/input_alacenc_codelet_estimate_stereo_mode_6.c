#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int best = 0;
uint64_t score[4] = {0, 0, 0, 0};

void init_vars() {
    // Initialize score array with distinct values to allow meaningful comparison
    score[0] = 100;
    score[1] = 80;
    score[2] = 90;
    score[3] = 70;
    // Ensure best starts at valid index within [0,3]
    best = 0;
}