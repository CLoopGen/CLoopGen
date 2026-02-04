#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *dst;
uint16_t *src1;
uint16_t *src2;
unsigned int mask;
int w;
long i;

void init_vars() {
    w = 67108864; // 64M elements, ~128MB total data (3 arrays), target ~0.01s runtime
    mask = 0xFFFF;

    dst = (uint16_t*)aligned_alloc(32, w * sizeof(uint16_t));
    src1 = (uint16_t*)aligned_alloc(32, w * sizeof(uint16_t));
    src2 = (uint16_t*)aligned_alloc(32, w * sizeof(uint16_t));

    for (int j = 0; j < w; j++) {
        src1[j] = (uint16_t)(j & 0xFFFF);
        src2[j] = (uint16_t)((j + 12345) & 0xFFFF);
    }

    i = 0;
}