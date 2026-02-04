#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

const uint8_t ff_zigzag_direct[64] = {
    0,  1,  8,  16, 9,  2,  3,  10,
    17, 24, 32, 25, 18, 11, 4,  5,
    12, 19, 26, 33, 40, 48, 41, 34,
    27, 20, 13, 6,  7,  14, 21, 28,
    35, 42, 49, 56, 57, 50, 43, 36,
    29, 22, 15, 23, 30, 37, 44, 51,
    58, 59, 52, 45, 38, 31, 39, 46,
    53, 60, 61, 54, 47, 55, 62, 63
};

uint8_t unscaled_quant_matrix[64];

int *output;

int qscale;
int i;

void init_vars() {
    for (int idx = 0; idx < 64; idx++) {
        unscaled_quant_matrix[idx] = (uint8_t)(idx * 3 + 7);
    }
    qscale = 15;

    output = (int*)malloc(64 * sizeof(int));
    if (!output) {
        exit(1);
    }
}