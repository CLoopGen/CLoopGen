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

#define DATA_SIZE (64 * 1024 * 1024)  // ~64MB total data to target ~0.01 sec runtime
static uint16_t *dst_data;
static uint16_t *src_data;

void init_vars() {
    A = 42;  // arbitrary non-zero value for computation
    h = DATA_SIZE / (4 * sizeof(uint16_t));  // number of iterations to process all data in chunks of 4
    stride = 4;  // stride advances by 4 elements per iteration

    // Allocate aligned memory to ensure no access violations
    dst_data = aligned_alloc(32, DATA_SIZE);
    src_data = aligned_alloc(32, DATA_SIZE);

    if (!dst_data || !src_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize source and destination arrays
    for (size_t idx = 0; idx < DATA_SIZE / sizeof(uint16_t); ++idx) {
        src_data[idx] = idx & 0x3FF;  // small values to prevent overflow
        dst_data[idx] = (idx + 1) & 0x3FF;
    }

    dst = dst_data;
    src = src_data;
}