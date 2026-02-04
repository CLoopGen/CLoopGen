#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w = 1920;
int h = 1080;
uint8_t *dst;
int dst_linesize = 1920;
uint8_t *src;
int src_linesize = 1920;
int i;
int j;

void init_vars() {
    size_t total_size = (size_t)w * h;
    dst = aligned_alloc(32, total_size * sizeof(uint8_t));
    src = aligned_alloc(32, total_size * sizeof(uint8_t));

    if (!dst || !src) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < total_size; idx++) {
        dst[idx] = rand() % 256;
        src[idx] = rand() % 256;
    }
}