#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int h;
uint8_t *dst;
uint8_t *src;
int A;
int i;

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    // Set parameters for ~0.01s runtime: use ~16-32MB total data as a reasonable estimate
    size_t total_data_size = 16 * (1 << 20); // 16 MB

    // Choose height and stride such that h * abs(stride) covers the data appropriately
    // We'll assume vertical access pattern with moderate stride (e.g., image-like rows)
    stride = 64; // simulate a row stride of 64 bytes (e.g., small image width)

    h = total_data_size / abs(stride); // number of rows to reach target data volume

    // Ensure minimum h
    if (h == 0) h = 1;

    // Allocate buffers with padding to avoid overflow during last access (we access index 1)
    size_t buffer_size = (h - 1) * abs(stride) + 2; // at least enough for h rows, each accessing [0] and [1]

    dst_buffer = aligned_alloc(64, buffer_size);
    src_buffer = aligned_alloc(64, buffer_size);

    if (!dst_buffer || !src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    dst = dst_buffer;
    src = src_buffer;

    A = 45; // arbitrary non-zero coefficient for computation

    // Initialize src data to prevent undefined behavior
    for (int j = 0; j < buffer_size; j++) {
        src_buffer[j] = j & 0xFF;
    }
}