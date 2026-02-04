#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int ndim;
extern char *dst_data;
extern char *src_data;
extern int idim;
extern npy_intp shape_it[64];
extern npy_intp dst_strides_it[64];
extern npy_intp src_strides_it[64];
extern npy_intp coord[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (flatten multi-dimensional index)
    npy_intp dst_offset = 0;
    npy_intp src_offset = 0;
    for (idim = 1; idim < ndim; ++idim) {
        if (++coord[idim] == shape_it[idim]) {
            coord[idim] = 0;
        } else {
            // Recompute linear offset based on current coordinates
            dst_offset = 0;
            src_offset = 0;
            for (int j = 1; j < ndim; ++j) {
                dst_offset += coord[j] * dst_strides_it[j];
                src_offset += coord[j] * src_strides_it[j];
            }
            dst_data = dst_data - dst_offset + dst_strides_it[idim]; // Adjust to next position
            src_data = src_data - src_offset + src_strides_it[idim];
            break;
        }
    }
}
