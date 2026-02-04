#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int ndim;
extern char *data;
extern int idim;
extern npy_intp shape[64];
extern npy_intp strides[64];
extern npy_intp coord[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of updating coordinates and conditionally adjusting data pointer,
    // we precompute total offset assuming row-major order and access memory consecutively.
    npy_intp total_stride = 0;
    for ((idim) = 1; (idim) < (ndim); ++(idim)) {
        if (++(coord)[idim] != (shape)[idim]) {
            total_stride += (strides)[idim];
            break;
        } else {
            total_stride -= ((shape)[idim] - 1) * (strides)[idim];
            (coord)[idim] = 0;
        }
    }
    (data) += total_stride;
}
