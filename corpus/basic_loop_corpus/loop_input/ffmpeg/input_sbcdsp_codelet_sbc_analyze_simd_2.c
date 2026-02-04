#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int subbands = 16777216; // ~64 MB of input data (16M elements * 4 bytes per int32_t)
int32_t t1[16777216];
int16_t t2[16777216];
int i;

void init_vars() {
    for (i = 0; i < subbands; i++) {
        t1[i] = (int32_t)(i * 314159L);
    }
}