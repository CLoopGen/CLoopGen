#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

static size_t total_src_size;
static size_t total_dst_size;

uint8_t *dst;
uint8_t *src;
int block;
int i;

void init_vars() {
    total_src_size = 1 << 20; // 1MB of source data
    total_dst_size = (total_src_size / 3) * 8;

    src = aligned_alloc(32, total_src_size);
    dst = aligned_alloc(32, total_dst_size);

    if (!src || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t j = 0; j < total_src_size; j++) {
        src[j] = rand() & 0xFF;
    }
}