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
    dst_buffer = aligned_alloc(32, size * sizeof(uint8_t) * 2);  // Ensure dst is large enough

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < size; j++) {
        src_buffer[j] = rand() % 5;
    }

    // Ensure no out-of-bounds access: avoid triggering conditions at boundaries
    // Fix positions near start and end to prevent invalid memory access
    src_buffer[0] = 1;
    src_buffer[1] = 2;
    if (size > 1) {
        src_buffer[size - 1] = 1;
    }

    src = src_buffer;
    dst = dst_buffer;
}