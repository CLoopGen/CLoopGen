#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *dst;
uint16_t *src1;
uint16_t *src2;
int w;
long i;
unsigned long pw_lsb;
unsigned long pw_msb;

void init_vars() {
    w = 64 * 1024 * 1024 / sizeof(uint16_t); // ~64MB of data to target ~0.01s runtime
    size_t alignment = _Alignof(long);
    size_t size = w * sizeof(uint16_t);

    src1 = (uint16_t*)aligned_alloc(alignment, size);
    src2 = (uint16_t*)aligned_alloc(alignment, size);
    dst  = (uint16_t*)aligned_alloc(alignment, size);

    pw_lsb = 0x5555555555555555ULL;
    pw_msb = 0xAAAAAAAAAAAAAAAAULL;

    for (int j = 0; j < w; j++) {
        src1[j] = (uint16_t)(j & 0xFFFF);
        src2[j] = (uint16_t)((j >> 1) & 0xFFFF);
    }
}