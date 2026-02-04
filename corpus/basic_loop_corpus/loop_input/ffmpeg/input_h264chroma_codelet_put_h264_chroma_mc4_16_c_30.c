#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride = 1024;
int h = 256;

uint16_t *dst;
uint16_t *src;

int A = 17;
int B = 31;
int C = 15;
int D = 23;

int i;

void init_vars() {
    const size_t total_size = stride * h * sizeof(uint16_t);
    dst = aligned_alloc(32, total_size);
    src = aligned_alloc(32, total_size);

    for (size_t idx = 0; idx < total_size / sizeof(uint16_t); ++idx) {
        src[idx] = rand() & 0xFFFF;
        dst[idx] = 0;
    }
}