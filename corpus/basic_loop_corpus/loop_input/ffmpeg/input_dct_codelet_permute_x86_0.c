#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t idct_simple_mmx_perm[64];
int16_t dst[64];
int16_t src[64];
int i;

void init_vars() {
    for (i = 0; i < 64; i++) {
        src[i] = (int16_t)(i * 2);
        idct_simple_mmx_perm[i] = (uint8_t)((41 * i) % 64); // Pseudo-random permutation to cover all indices
        dst[i] = 0;
    }
}