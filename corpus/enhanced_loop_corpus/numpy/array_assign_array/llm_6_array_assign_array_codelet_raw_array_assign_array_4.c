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
    npy_intp temp_dst_stride = 0;
    npy_intp temp_src_stride = 0;
    for ((idim) = 1; (idim) < (ndim); ++(idim)) {
        if (++(coord)[idim] == (shape_it)[idim]) {
            (coord)[idim] = 0;
            temp_dst_stride += (dst_strides_it)[idim];
            temp_src_stride += (src_strides_it)[idim];
        } else {
            (dst_data) += (dst_strides_it)[idim];
            (src_data) += (src_strides_it)[idim];
            break;
        }
    }
    (dst_data) -= ((shape_it)[idim-1] - 1) * temp_dst_stride;
    (src_data) -= ((shape_it)[idim-1] - 1) * temp_src_stride;
}
