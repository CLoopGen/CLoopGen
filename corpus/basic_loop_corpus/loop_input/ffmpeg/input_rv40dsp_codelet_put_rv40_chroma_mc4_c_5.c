#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB for ~0.01s runtime estimate

uint8_t *dst;
uint8_t *src;
ptrdiff_t stride;
int h = 16384;
int A = 15;
int B = -7;
int C = 9;
int D = -5;
int i;
int bias = 32;

void init_vars() {
    size_t total_size = DATA_SIZE;
    src = aligned_alloc(32, total_size);
    dst = aligned_alloc(32, total_size);

    if (!src || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_size; i++) {
        src[i] = rand() % 256;
        dst[i] = 0;
    }

    stride = 4096; 
}