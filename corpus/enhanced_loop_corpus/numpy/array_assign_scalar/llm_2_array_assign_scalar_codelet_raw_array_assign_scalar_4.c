#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int ndim;
extern char *dst_data;
extern int idim;
extern npy_intp shape_it[64];
extern npy_intp dst_strides_it[64];
extern npy_intp coord[64];

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive Memory Access (flatten multi-dimensional index)
    npy_intp flat_index = 0;
    npy_intp total_stride = 1;
    
    for (idim = 0; idim < ndim; ++idim) {
        flat_index += coord[idim] * total_stride;
        total_stride *= shape_it[idim];
    }

    // Reset all dimensions and simulate increment
    for (idim = 1; idim < ndim; ++idim) {
        if (++coord[idim] == shape_it[idim]) {
            coord[idim] = 0;
        } else {
            break;
        }
    }

    // Recompute flat index after increment
    flat_index = 0;
    total_stride = 1;
    for (idim = 0; idim < ndim; ++idim) {
        flat_index += coord[idim] * total_stride;
        total_stride *= shape_it[idim];
    }

    dst_data = dst_data - flat_index * dst_strides_it[0] + 
               ((flat_index + 1) % shape_it[0]) * dst_strides_it[0];
}
