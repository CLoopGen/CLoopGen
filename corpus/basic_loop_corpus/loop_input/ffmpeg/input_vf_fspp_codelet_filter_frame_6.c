#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

short custom_threshold[64];
int i;
int bias;
int custom_threshold_m[64];

void init_vars() {
    // Initialize bias to a reasonable value for meaningful computation
    bias = 1000;

    // Initialize custom_threshold with non-zero values to ensure meaningful calculation
    for (int idx = 0; idx < 64; idx++) {
        custom_threshold[idx] = (short)(idx * 10 + 31);
    }

    // Initialize loop index and output array if needed (will be overwritten in loop, but safe)
    i = 0;
    for (int idx = 0; idx < 64; idx++) {
        custom_threshold_m[idx] = 0;
    }
}