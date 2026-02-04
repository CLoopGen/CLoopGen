#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

double coefficients[64];
short *block;
unsigned int i;
unsigned int j;
unsigned int k;
double out[64];

void init_vars() {
    block = (short *)aligned_alloc(32, sizeof(short) * 64);
    
    for (int idx = 0; idx < 64; ++idx) {
        coefficients[idx] = 1.0 + idx * 0.01;
        block[idx] = (short)(idx % 256);
        out[idx] = 0.0;
    }
}