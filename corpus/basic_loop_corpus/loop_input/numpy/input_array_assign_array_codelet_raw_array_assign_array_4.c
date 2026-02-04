#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

int ndim = 4;
char *dst_data;
char *src_data;
int idim = 0;
npy_intp shape_it[64];
npy_intp dst_strides_it[64];
npy_intp src_strides_it[64];
npy_intp coord[64];

void init_vars() {
    const size_t total_size = 64 * 1024 * 1024; // 64 MB total data size
    dst_data = (char*)aligned_alloc(64, total_size);
    src_data = (char*)aligned_alloc(64, total_size);

    if (!dst_data || !src_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize dimensions
    ndim = 4;
    shape_it[0] = 4;
    shape_it[1] = 16;
    shape_it[2] = 64;
    shape_it[3] = 128;

    // Row-major strides (in bytes)
    dst_strides_it[3] = 1;
    src_strides_it[3] = 1;
    for (int i = ndim - 2; i >= 0; i--) {
        dst_strides_it[i] = dst_strides_it[i+1] * shape_it[i+1];
        src_strides_it[i] = src_strides_it[i+1] * shape_it[i+1];
    }

    // Zero-initialize coordinates
    for (int i = 0; i < ndim; i++) {
        coord[i] = 0;
    }
    coord[0] = 0; // Start from first outer dimension

    // Ensure initial pointers are at start
    dst_data = dst_data;
    src_data = src_data;

    // Warm up memory
    for (size_t i = 0; i < total_size; i += 64) {
        dst_data[i] = 0;
        src_data[i] = 1;
    }
}