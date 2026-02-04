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

void init_vars() {
    size = 64 * 1024 * 1024;  // 64 MB input size for ~0.01 sec runtime on modern CPU
    dsize = 0;
    i = 0;

    src_buffer = aligned_alloc(32, size * sizeof(uint8_t));
    dst_buffer = aligned_alloc(32, size * 2 * sizeof(uint8_t));  // Over-allocate to prevent overflow

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    for (int j = 0; j < size; j++) {
        src_buffer[j] = rand() % 256;
    }

    // Ensure no out-of-bounds access in loop by avoiding triggering condition at boundaries
    // Avoid pattern that would cause read past end: src[1] when i == size-1
    // So ensure that near the end, conditions leading to src++ increment are not met

    // Fix last two elements to avoid triggering the complex condition
    if (size >= 1) {
        src_buffer[size - 1] = 1;
    }
    if (size >= 2) {
        src_buffer[size - 2] = 1;
    }

    src = src_buffer;
    dst = dst_buffer;
}