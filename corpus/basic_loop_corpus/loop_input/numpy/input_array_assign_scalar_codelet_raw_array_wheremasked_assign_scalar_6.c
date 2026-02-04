#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

int ndim = 4;
char *dst_data;
char *wheremask_data;
int idim;
npy_intp shape_it[64];
npy_intp dst_strides_it[64];
npy_intp wheremask_strides_it[64];
npy_intp coord[64];

void init_vars() {
    // Set up dimensions and shapes
    const npy_intp total_size = 1 << 20; // ~1MB of data for predictable timing (~0.01 sec)
    
    // Use a 4D array with roughly equal dimensions: 32 x 32 x 32 x 32 = 1,048,576 elements
    shape_it[0] = 32;
    shape_it[1] = 32;
    shape_it[2] = 32;
    shape_it[3] = 32;
    for (int i = 4; i < 64; ++i) {
        shape_it[i] = 1;
    }

    // Compute strides in C order
    dst_strides_it[ndim - 1] = 1;
    wheremask_strides_it[ndim - 1] = 1;
    for (int i = ndim - 2; i >= 0; --i) {
        dst_strides_it[i] = dst_strides_it[i + 1] * shape_it[i + 1];
        wheremask_strides_it[i] = wheremask_strides_it[i + 1] * shape_it[i + 1];
    }
    for (int i = ndim; i < 64; ++i) {
        dst_strides_it[i] = 0;
        wheremask_strides_it[i] = 0;
    }

    // Allocate data buffers
    dst_data = (char*)calloc(total_size, sizeof(char));
    wheremask_data = (char*)calloc(total_size, sizeof(char));

    // Initialize coordinates to zero
    for (int i = 0; i < 64; ++i) {
        coord[i] = 0;
    }

    // Ensure initial position is within bounds
    idim = 0;
}