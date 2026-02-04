#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *dst;
float *src;
int dst_stridea;
int dst_strideb;
int src_stridea;
int src_strideb;
int i;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB of float data

static float *alloc_aligned_float_array(size_t n) {
    void *ptr;
    if (posix_memalign(&ptr, 32, n * sizeof(float)) != 0) {
        return NULL;
    }
    return (float *)ptr;
}

void init_vars() {
    // Initialize strides
    src_stridea = 1;
    src_strideb = 8;
    dst_stridea = 1;
    dst_strideb = 8;

    // Total number of elements needed: at least 8 rows of 8 elements each due to loop accessing indices 0-7 with src_stridea
    const int num_rows = 8;
    const int num_cols = 8;
    const int total_elements = num_rows * num_cols;

    // Allocate input and output arrays
    src = alloc_aligned_float_array(total_elements);
    dst = alloc_aligned_float_array(total_elements);

    if (!src || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize src data with non-zero values to ensure meaningful computation
    for (int idx = 0; idx < total_elements; ++idx) {
        src[idx] = (float)(idx % 128) * 0.5f;
    }

    // Ensure i is initialized properly before use in loop
    i = 0;
}