#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w;
uint8_t *in;
uint8_t *out;
int j;

static uint8_t *in_buffer;
static uint8_t *out_buffer;
static size_t total_size;

void init_vars() {
    total_size = 128 * 1024 * 1024; // 128 MB of data

    in_buffer = (uint8_t *)aligned_alloc(64, total_size);
    out_buffer = (uint8_t *)aligned_alloc(64, total_size);

    if (!in_buffer || !out_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_size; i++) {
        in_buffer[i] = rand() & 0xFF;
    }

    in = in_buffer + total_size - (total_size % 6); // Align to multiple of 6 from end
    out = out_buffer;
    w = (total_size / 6) - 1; // Number of complete 6-byte chunks minus one to avoid overflow
}