#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *out;
int blk_size;
int x;
int16_t dc_coeff;

void init_vars() {
    blk_size = 131072; // 256KB of data (131072 * 2 bytes = 256KB), target ~0.01 sec runtime
    dc_coeff = 42;     // arbitrary value for dc_coeff
    out = (int16_t*)aligned_alloc(_Alignof(int16_t), blk_size * sizeof(int16_t));
    if (!out) {
        exit(1);
    }
}