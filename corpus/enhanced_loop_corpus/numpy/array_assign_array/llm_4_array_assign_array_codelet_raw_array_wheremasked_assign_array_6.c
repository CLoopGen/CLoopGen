#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int ndim;
extern char *dst_data;
extern char *src_data;
extern char *wheremask_data;
extern int idim;
extern npy_intp shape_it[64];
extern npy_intp dst_strides_it[64];
extern npy_intp src_strides_it[64];
extern npy_intp wheremask_strides_it[64];
extern npy_intp coord[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for ((idim) = 1; (idim) < (ndim); ++(idim)) {
        (coord)[idim]++;
        if ((coord)[idim] >= (shape_it)[idim]) {
            (coord)[idim] = 0;
            npy_intp stride_factor = ((shape_it)[idim] - 1);
            (dst_data) -= stride_factor * (dst_strides_it)[idim];
            (src_data) -= stride_factor * (src_strides_it)[idim];
            (wheremask_data) -= stride_factor * (wheremask_strides_it)[idim];
        } else {
            (dst_data) += (dst_strides_it)[idim];
            (src_data) += (src_strides_it)[idim];
            (wheremask_data) += (wheremask_strides_it)[idim];
            break;
        }
    }
}
