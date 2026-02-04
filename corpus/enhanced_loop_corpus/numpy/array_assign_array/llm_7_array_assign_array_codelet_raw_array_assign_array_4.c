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
    npy_intp delta_dst = 0;
    npy_intp delta_src = 0;
    int updated = 0;
    for ((idim) = 1; (idim) < (ndim); ++(idim)) {
        if (!updated && ++(coord)[idim] != (shape_it)[idim]) {
            delta_dst = (dst_strides_it)[idim];
            delta_src = (src_strides_it)[idim];
            updated = 1;
        } else if (!updated) {
            (coord)[idim] = 0;
            delta_dst -= (dst_strides_it)[idim];
            delta_src -= (src_strides_it)[idim];
        }
    }
    (dst_data) += delta_dst;
    (src_data) += delta_src;
}
