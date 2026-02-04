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

#define DATA_SIZE (128 << 20)  // 128 MB total data size
static uint16_t *dst_data;
static uint16_t *src_data;

void init_vars() {
    // Initialize scalar variables
    A = 42;  // arbitrary non-zero value for computation
    h = (DATA_SIZE / sizeof(uint16_t)) / 8;  // number of iterations to process all data in chunks of 8 elements
    stride = 8;  // advance by 8 elements per iteration

    // Allocate memory for source and destination arrays
    dst_data = aligned_alloc(32, DATA_SIZE);
    src_data = aligned_alloc(32, DATA_SIZE);

    if (!dst_data || !src_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize source data with non-zero values for meaningful computation
    for (int idx = 0; idx < (DATA_SIZE / sizeof(uint16_t)); ++idx) {
        src_data[idx] = (uint16_t)(idx & 0xFFFF);
    }

    // Set pointers to start of data
    dst = dst_data;
    src = src_data;
}