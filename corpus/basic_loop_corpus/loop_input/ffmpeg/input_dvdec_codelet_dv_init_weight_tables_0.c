#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int c;
int s;

uint32_t *factor1;
uint32_t *factor2;

uint8_t dv100_qstep[16] = {
    1, 2, 3, 4, 5, 6, 7, 8,
    9, 10, 11, 12, 13, 14, 15, 16
};

uint16_t *iweight1;
uint16_t *iweight2;

void init_vars() {
    factor1 = (uint32_t*)aligned_alloc(32, sizeof(uint32_t) * 64 * 16 * 4);
    factor2 = (uint32_t*)aligned_alloc(32, sizeof(uint32_t) * 64 * 16 * 4);
    iweight1 = (uint16_t*)aligned_alloc(32, sizeof(uint16_t) * 64);
    iweight2 = (uint16_t*)aligned_alloc(32, sizeof(uint16_t) * 64);

    for (int idx = 0; idx < 64; idx++) {
        iweight1[idx] = idx + 1;
        iweight2[idx] = idx + 2;
    }
}