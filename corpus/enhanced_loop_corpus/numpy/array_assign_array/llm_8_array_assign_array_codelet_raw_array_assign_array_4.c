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
    for ((idim) = 1; (idim) < (ndim); ++(idim)) {
        npy_intp dst_stride_val = (dst_strides_it)[idim];
        npy_intp src_stride_val = (src_strides_it)[idim];
        npy_intp shape_val = (shape_it)[idim];
        if (++(coord)[idim] == shape_val) {
            (coord)[idim] = 0;
            (dst_data) -= (shape_val - 1) * dst_stride_val;
            (src_data) -= (shape_val - 1) * src_stride_val;
        } else {
            (dst_data) += dst_stride_val;
            (src_data) += src_stride_val;
            break;
        }
    }
}
