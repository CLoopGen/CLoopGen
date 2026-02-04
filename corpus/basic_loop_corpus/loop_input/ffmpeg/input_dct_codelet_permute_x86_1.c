#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t idct_sse2_row_perm[8] = {0, 1, 2, 3, 4, 5, 6, 7};
int16_t dst[64];
int16_t src[64];
int i;

void init_vars() {
    for (int idx = 0; idx < 64; idx++) {
        src[idx] = (int16_t)(idx * 2);
    }
    for (int idx = 0; idx < 8; idx++) {
        idct_sse2_row_perm[idx] = (uint8_t)(7 - idx);
    }
    for (int idx = 0; idx < 64; idx++) {
        dst[idx] = 0;
    }
    i = 0;
}