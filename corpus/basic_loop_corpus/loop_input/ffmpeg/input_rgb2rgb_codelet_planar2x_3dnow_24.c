#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint8_t *dst;
int srcWidth;
int x;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    srcWidth = 64 * 1024 * 1024; // 64 million elements to target ~0.01 sec runtime

    src_buffer = (uint8_t *)aligned_alloc(32, sizeof(uint8_t) * srcWidth);
    dst_buffer = (uint8_t *)aligned_alloc(32, sizeof(uint8_t) * (2 * srcWidth));

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < srcWidth; i++) {
        src_buffer[i] = rand() & 0xFF;
    }

    src = src_buffer;
    dst = dst_buffer;
}