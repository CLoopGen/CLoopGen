#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
ptrdiff_t stride;
ptrdiff_t width;
int A;
int B;
int C;
int i;

static uint8_t *internal_src;

void init_vars() {
    width = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec on modern CPU
    stride = 1024;
    
    internal_src = (uint8_t *)aligned_alloc(32, width + stride + 1);
    if (!internal_src) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    src = internal_src + stride; // Base pointer adjusted so that i - stride is in bounds

    for (ptrdiff_t j = 0; j < width + stride + 1; j++) {
        internal_src[j] = rand() & 255;
    }

    A = 0;
    B = 0;
    C = 0;
    i = 0;
}