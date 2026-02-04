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
static size_t src_size = 1 << 20; // 1MB data for ~0.01 sec runtime estimate
static size_t dst_size = 1 << 20;

void init_vars() {
    src_buffer = calloc(src_size, sizeof(uint8_t));
    dst_buffer = calloc(dst_size, sizeof(uint8_t));
    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    src = src_buffer;
    dst = dst_buffer;
    size = src_size;
    dsize = 0;
    i = 0;

    for (size_t idx = 0; idx < src_size; idx++) {
        src_buffer[idx] = rand() % 5;
    }
}