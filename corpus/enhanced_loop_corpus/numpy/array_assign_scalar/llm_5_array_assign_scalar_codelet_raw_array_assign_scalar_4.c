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



void loop(){
for ((idim) = 1; (idim) < (ndim); ++(idim)) {
    npy_intp new_coord = (coord)[idim] + 1;
    npy_intp stride = (dst_strides_it)[idim];
    if (new_coord >= (shape_it)[idim]) {
        (coord)[idim] = 0;
        (dst_data) -= ((shape_it)[idim] - 1) * stride;
    } else {
        (coord)[idim] = new_coord;
        (dst_data) += stride;
        break;
    }
}
}
