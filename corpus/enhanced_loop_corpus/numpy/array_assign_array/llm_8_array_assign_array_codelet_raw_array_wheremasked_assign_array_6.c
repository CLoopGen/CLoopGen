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
    npy_intp stride = (dst_strides_it)[idim];
    npy_intp size = (shape_it)[idim];
    if (++(coord)[idim] == size) {
        (coord)[idim] = 0;
        npy_intp step = (size - 1) * stride;
        (dst_data) -= step;
        (src_data) -= (size - 1) * (src_strides_it)[idim];
        (wheremask_data) -= (size - 1) * (wheremask_strides_it)[idim];
    } else {
        (dst_data) += stride;
        (src_data) += (src_strides_it)[idim];
        (wheremask_data) += (wheremask_strides_it)[idim];
        break;
    }
}
}
