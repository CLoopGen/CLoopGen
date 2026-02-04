#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int grouping;
int attacks[9];
int i;

void init_vars() {
    for (int j = 0; j < 9; j++) {
        attacks[j] = 0;
    }
    // Set one element to non-zero near the end to ensure loop runs through most indices
    attacks[8] = 1;
    grouping = 0;
    i = 0;
}