#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int ndim;
extern char *dst_data;
extern char *wheremask_data;
extern int idim;
extern npy_intp shape_it[64];
extern npy_intp dst_strides_it[64];
extern npy_intp wheremask_strides_it[64];
extern npy_intp coord[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for ((idim) = 1; (idim) < (ndim); ++(idim)) {
    npy_intp prev_coord = (coord)[idim];
    (coord)[idim] = (prev_coord + 1) % (shape_it)[idim];
    npy_intp delta = (coord)[idim] > prev_coord ? 1 : -(shape_it)[idim] - 1;
    (dst_data) += delta * (dst_strides_it)[idim];
    (wheremask_data) += delta * (wheremask_strides_it)[idim];
    if ((coord)[idim] != 0) {
        break;
    }
}
}
