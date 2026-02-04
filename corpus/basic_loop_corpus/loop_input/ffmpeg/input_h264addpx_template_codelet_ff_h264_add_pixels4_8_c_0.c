#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int stride;
int i;
uint8_t *dst;
int16_t *src;

static uint8_t *dst_buffer;
static int16_t *src_buffer;
static size_t total_data_size = 64 * 1024 * 1024; // 64 MB for sufficient runtime (~0.01 sec)

void init_vars() {
    stride = 4; // ensures dst advances by 4 bytes per iteration, matching 4 uint8_t writes

    // Allocate buffers
    dst_buffer = aligned_alloc(32, total_data_size);
    src_buffer = aligned_alloc(32, total_data_size);

    // Initialize buffers to zero to ensure defined behavior
    for (size_t idx = 0; idx < total_data_size; idx++) {
        dst_buffer[idx] = 0;
        if (idx < total_data_size / sizeof(int16_t))
            ((uint8_t*)src_buffer)[idx] = rand() % 256;
    }

    // Set pointers to start of buffers
    dst = dst_buffer;
    src = src_buffer;

    // Adjust loop bound to prevent out-of-bounds access:
    // Each iteration accesses 4 elements of src (4 * sizeof(int16_t) = 8 bytes)
    // and writes to 4 bytes in dst.
    // Total iterations must not exceed available blocks of 4 in src or dst spacing by stride.
    // We assume the original loop runs 4 iterations — so we require at least 16 bytes in dst per column and 8 bytes in src.
    // Since we're only running 4 iterations, bounds are safe as long as allocations >= (4 + 3*stride) for dst and >= 16 for src.
    // Our large allocation ensures this.

    i = 0;
}