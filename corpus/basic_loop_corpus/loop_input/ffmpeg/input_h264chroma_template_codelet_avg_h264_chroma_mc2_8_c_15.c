#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int h;
uint8_t *dst;
uint8_t *src;
int A;
int B;
int C;
int D;
int i;

#define DATA_SIZE (64 * 1024 * 1024)  // ~64 MB for sufficient runtime (~0.01 sec on modern CPU)
static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    // Initialize coefficients
    A = 15;
    B = 26;
    C = 37;
    D = 48;

    // Set image height and stride
    h = 8192;  // Adjust to fit data size
    stride = 8192;  // Assume square-like block

    // Ensure total memory does not exceed DATA_SIZE
    while (h * stride > DATA_SIZE / 2) {
        h -= 1024;
        if (h <= 0) {
            h = 1;
            break;
        }
    }

    // Allocate buffers with padding to prevent out-of-bounds access
    src_buffer = aligned_alloc(64, h * stride + 2 * stride + 4);
    dst_buffer = aligned_alloc(64, h * stride + 2 * stride + 4);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize src and dst pointers to start of usable region
    src = src_buffer + stride + 1;  // Leave room for src[-1], src[stride-1], etc.
    dst = dst_buffer + stride + 1;

    // Initialize source data
    for (int y = 0; y < h + 1; y++) {
        for (int x = 0; x < stride + 2; x++) {
            src_buffer[y * stride + x] = rand() & 0xFF;
            dst_buffer[y * stride + x] = rand() & 0xFF;
        }
    }

    // Initialize loop index
    i = 0;
}