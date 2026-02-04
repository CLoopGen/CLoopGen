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
    // Instead of using strided access, accumulate total offset in bytes assuming row-major order.
    // We precompute a flat byte offset using cumulative strides and coordinates.
    npy_intp total_offset = 0;
    for ((idim) = 1; (idim) < (ndim); ++(idim)) {
        if (++(coord)[idim] == (shape)[idim]) {
            (coord)[idim] = 0;
            // Recompute offset from coordinates and strides
            total_offset -= (strides)[idim];
        } else {
            total_offset += (strides)[idim];
            break;
        }
    }
    (data) += total_offset;
}
