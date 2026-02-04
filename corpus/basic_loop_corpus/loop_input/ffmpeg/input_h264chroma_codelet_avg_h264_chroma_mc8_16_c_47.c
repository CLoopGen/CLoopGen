#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int h;
uint16_t *dst;
uint16_t *src;
int A;
int i;

#define DATA_SIZE (64 * 1024 * sizeof(uint16_t))
static uint16_t dst_data[64 * 1024];
static uint16_t src_data[64 * 1024];

void init_vars() {
    // Initialize scalar variables
    A = 42;  // Arbitrary non-zero value for computation
    h = 8192;  // Number of iterations to process all data with 8 elements per iteration
    stride = 8;  // Advance by 8 elements per row

    // Initialize pointers
    dst = dst_data;
    src = src_data;

    // Initialize input data to avoid undefined behavior
    for (int idx = 0; idx < 64 * 1024; idx++) {
        dst_data[idx] = idx % 257;  // Prime modulus to vary values
        src_data[idx] = (idx * 3) % 199;
    }

    // Ensure that memory accesses in loop are safe:
    // Loop accesses dst[0..7] and src[0..7] each iteration, so we need at least
    // (h * stride) total elements, which is satisfied by our array sizes.
}