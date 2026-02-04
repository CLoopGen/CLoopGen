#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t simple_mmx_permutation[64] = {
    0,  1,  2,  3,  4,  5,  6,  7,
    8,  9,  10, 11, 12, 13, 14, 15,
    16, 17, 18, 19, 20, 21, 22, 23,
    24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 34, 35, 36, 37, 38, 39,
    40, 41, 42, 43, 44, 45, 46, 47,
    48, 49, 50, 51, 52, 53, 54, 55,
    56, 57, 58, 59, 60, 61, 62, 63
};

uint8_t *idct_permutation;

int i;

void init_vars() {
    idct_permutation = (uint8_t*)aligned_alloc(16, 64);
    if (!idct_permutation) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}