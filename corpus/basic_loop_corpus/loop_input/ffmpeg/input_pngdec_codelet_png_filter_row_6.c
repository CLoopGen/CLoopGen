#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
int size;
int bpp;
int i;
int p;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    bpp = 4;
    size = 67108864; // 64 million elements * 4 bytes = 256 MB total data
    src_buffer = aligned_alloc(32, size + 32);
    dst_buffer = aligned_alloc(32, size + 32);

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    src = src_buffer;
    dst = dst_buffer;

    for (int j = 0; j < size; j += sizeof(int)) {
        int val = rand();
        *(int*)(src + j) = val;
    }

    i = 0;
    p = 0;
}