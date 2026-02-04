#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t block[64];
uint32_t quant[64];
int coef_count = 64;
int coef_idx[64];
uint8_t *scan;
int i;

void init_vars() {
    scan = (uint8_t *)aligned_alloc(64, sizeof(uint8_t) * 64);
    for (int j = 0; j < 64; j++) {
        block[j] = rand() % 1000 - 500;
        quant[j] = rand() % 100 + 1;
        coef_idx[j] = j;
        scan[j] = j;
    }
    coef_count = 64;
}