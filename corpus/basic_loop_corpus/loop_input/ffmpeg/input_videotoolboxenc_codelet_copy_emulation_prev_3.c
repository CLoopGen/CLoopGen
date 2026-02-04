#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

uint8_t *src;
uint8_t *dst;
int zeros;
uint8_t *dst_end;
uint8_t *src_end;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate

    src_buffer = aligned_alloc(64, data_size);
    dst_buffer = aligned_alloc(64, data_size * 2); // Larger to accommodate expansion

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize source buffer with pseudo-random but deterministic data
    for (size_t i = 0; i < data_size; i++) {
        src_buffer[i] = rand() % 250;
    }
    // Ensure we don't have long zero runs that could overflow dst
    // and place a zero roughly every 100 bytes
    for (size_t i = 100; i < data_size; i += 101) {
        src_buffer[i] = 0;
    }

    src = src_buffer;
    src_end = src_buffer + data_size;
    dst = dst_buffer;
    dst_end = dst_buffer + data_size * 2;
    zeros = 0;
}