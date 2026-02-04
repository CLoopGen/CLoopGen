#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int size;
uint8_t *dst;
int dsize;
int i;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static size_t src_size = 1 << 20; // 1MB for ~0.01 sec runtime on modern CPU
static size_t dst_size = 1 << 20;

void init_vars() {
    src_buffer = aligned_alloc(32, src_size);
    dst_buffer = aligned_alloc(32, dst_size);

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    for (size_t idx = 0; idx < src_size; idx++) {
        src_buffer[idx] = rand() % 256;
    }

    src = src_buffer;
    size = (int)src_size;
    dst = dst_buffer;
    dsize = 0;
}