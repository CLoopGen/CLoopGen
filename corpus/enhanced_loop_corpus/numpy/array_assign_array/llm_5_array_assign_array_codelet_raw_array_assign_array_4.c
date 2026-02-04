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



void loop() {
    for ((idim) = 1; (idim) < (ndim); ++(idim)) {
        npy_intp new_coord = (coord)[idim] + 1;
        int in_bounds = (new_coord < (shape_it)[idim]);
        (coord)[idim] = in_bounds ? new_coord : 0;

        npy_intp dst_stride_val = (dst_strides_it)[idim];
        npy_intp src_stride_val = (src_strides_it)[idim];
        npy_intp dst_offset = in_bounds ? dst_stride_val : -((shape_it)[idim] - 1) * dst_stride_val;
        npy_intp src_offset = in_bounds ? src_stride_val : -((shape_it)[idim] - 1) * src_stride_val;

        (dst_data) += dst_offset;
        (src_data) += src_offset;

        if (in_bounds) break;
    }
}
