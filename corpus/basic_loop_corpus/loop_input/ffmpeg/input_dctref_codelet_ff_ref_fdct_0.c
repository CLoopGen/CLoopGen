#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double coefficients[64] = {0};

short block_data[64] = {0};
short *block = block_data;

unsigned int i = 0;
unsigned int j = 0;
unsigned int k = 0;

double out[64] = {0};

void init_vars() {
    for (int idx = 0; idx < 64; ++idx) {
        coefficients[idx] = (double)(idx + 1);
    }
    for (int idx = 0; idx < 64; ++idx) {
        block_data[idx] = (short)(idx % 32);
    }
    for (int idx = 0; idx < 64; ++idx) {
        out[idx] = 0.0;
    }
    i = 0;
    j = 0;
    k = 0;
}