#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *bandE;
float sum[22];

static float bandE_data[22];

void init_vars() {
    for (int i = 0; i < 22; i++) {
        sum[i] = (float)(i * 3.14f);
    }
    bandE = bandE_data;
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}