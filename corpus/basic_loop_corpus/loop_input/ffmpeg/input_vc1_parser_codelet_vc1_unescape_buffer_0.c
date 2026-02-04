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
    dst_buffer = aligned_alloc(32, 2 * size * sizeof(uint8_t));  // worst-case: every byte copied

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    src = src_buffer;
    dst = dst_buffer;

    for (int j = 0; j < size; j++) {
        src_buffer[j] = rand() % 256;
    }

    // Ensure safe access for src[-2], src[-1], src[1] by padding logic via initialization bounds
    // Adjust first two and last one elements to avoid triggering condition near boundaries incorrectly
    if (size >= 1) src_buffer[0] = 1;
    if (size >= 2) src_buffer[1] = 1;
    if (size >= 3) src_buffer[size - 1] = 1;
}