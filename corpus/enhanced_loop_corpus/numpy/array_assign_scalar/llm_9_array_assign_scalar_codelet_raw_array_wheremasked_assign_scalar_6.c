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
    npy_intp s = (shape_it)[idim];
    npy_intp ds = (dst_strides_it)[idim];
    npy_intp ws = (wheremask_strides_it)[idim];
    npy_intp c = ++(coord)[idim];
    if (c == s) {
        (coord)[idim] = 0;
        (dst_data) -= (s - 1) * ds;
        (wheremask_data) -= (s - 1) * ws;
    } else {
        (dst_data) += ds;
        (wheremask_data) += ws;
        break;
    }
}
}
