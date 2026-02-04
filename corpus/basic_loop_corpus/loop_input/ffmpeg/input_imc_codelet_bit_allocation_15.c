#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
float highest;
float workT[32];
int found_indx;

void init_vars() {
    highest = -__FLT_MAX__;
    found_indx = 0;
    for (int idx = 0; idx < 32; idx++) {
        workT[idx] = (float)(idx * 3.5f); // Arbitrary non-repeating values
    }
    i = 0;
}