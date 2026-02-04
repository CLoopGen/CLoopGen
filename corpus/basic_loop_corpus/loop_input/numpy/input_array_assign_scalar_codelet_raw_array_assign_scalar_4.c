#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

int ndim = 4;
char *dst_data;
int idim;
npy_intp shape_it[64];
npy_intp dst_strides_it[64];
npy_intp coord[64];

void init_vars() {
    // Set up dimensions and shapes
    ndim = 4;
    shape_it[0] = 1;
    shape_it[1] = 256;
    shape_it[2] = 64;
    shape_it[3] = 16;
    
    // Initialize strides for C-contiguous layout
    dst_strides_it[3] = 1;
    for (int i = ndim - 2; i >= 0; i--) {
        dst_strides_it[i] = dst_strides_it[i + 1] * shape_it[i + 1];
    }
    
    // Total data size: product of all dimensions
    npy_intp total_size = 1;
    for (int i = 0; i < ndim; i++) {
        total_size *= shape_it[i];
    }
    
    // Allocate initialized data buffer (1 byte per element, ~256KB)
    dst_data = (char *)calloc(total_size, sizeof(char));
    if (!dst_data) {
        exit(1);
    }
    
    // Initialize coordinates to zero
    for (int i = 0; i < 64; i++) {
        coord[i] = 0;
    }
    
    // Prime the loop state: start after first iteration
    coord[0] = 1;
}