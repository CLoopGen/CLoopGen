#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
int dst_linesize;
int off;
int x;
int y;

void init_vars() {
    off = 32;
    dst_linesize = 16 * 16;
    size_t total_size = dst_linesize * (16 * 16);
    dst = aligned_alloc(32, total_size);
    if (!dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    for (size_t i = 0; i < total_size; i++) {
        dst[i] = 0;
    }
}