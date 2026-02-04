#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int h;
uint16_t *dst;
uint16_t *src;
int A;
int B;
int C;
int D;
int i;

#define DATA_SIZE (64 * 1024 * 1024)  // ~64MB of total data to ensure ~0.01s runtime
static uint16_t *dst_data;
static uint16_t *src_data;

void init_vars() {
    // Initialize coefficients
    A = 17;
    B = 31;
    C = 53;
    D = 79;

    // Set image height and stride
    h = 4096;
    stride = 8192;  // Ensures sufficient width for accessing src[2] and src[stride+2]

    // Allocate large enough arrays to avoid bounds issues and meet size target
    dst_data = aligned_alloc(32, DATA_SIZE);
    src_data = aligned_alloc(32, DATA_SIZE);

    if (!dst_data || !src_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize arrays with non-zero values for meaningful computation
    for (size_t idx = 0; idx < DATA_SIZE / sizeof(uint16_t); idx++) {
        src_data[idx] = (uint16_t)(idx % 257);
        dst_data[idx] = (uint16_t)((idx + 123) % 199);
    }

    // Point dst and src to valid starting region within allocated buffers
    // Leave padding so that [stride+2] accesses are safe
    dst = dst_data + stride + 3;
    src = src_data + stride + 3;
}