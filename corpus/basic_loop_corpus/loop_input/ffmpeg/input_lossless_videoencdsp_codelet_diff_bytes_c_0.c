#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src1;
uint8_t *src2;
intptr_t w;
long i;

static uint8_t *internal_dst;
static uint8_t *internal_src1;
static uint8_t *internal_src2;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; 

    internal_dst = aligned_alloc(32, data_size);
    internal_src1 = aligned_alloc(32, data_size);
    internal_src2 = aligned_alloc(32, data_size);

    if (!internal_dst || !internal_src1 || !internal_src2) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        internal_src1[idx] = rand() % 256;
        internal_src2[idx] = rand() % 256;
    }

    dst = internal_dst;
    src1 = internal_src1;
    src2 = internal_src2;
    w = data_size;
    i = 0;
}