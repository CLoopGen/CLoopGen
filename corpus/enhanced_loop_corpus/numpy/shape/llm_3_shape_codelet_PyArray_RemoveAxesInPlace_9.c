#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char npy_bool;

typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern  npy_bool *flags;
extern npy_intp *shape;
extern npy_intp *strides;
extern int idim;
extern int ndim;
extern int idim_out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern - process every second element forward, then fill in gaps
    // Simulates non-unit stride access by jumping in the array with a fixed step
    int step = 2;
    // First pass: handle even indices
    for (idim = 0; idim < ndim; idim += step) {
        if (!flags[idim]) {
            shape[idim_out] = shape[idim];
            strides[idim_out] = strides[idim];
            ++idim_out;
        }
    }
    // Second pass: handle odd indices (strided access completing full coverage)
    for (idim = 1; idim < ndim; idim += step) {
        if (!flags[idim]) {
            shape[idim_out] = shape[idim];
            strides[idim_out] = strides[idim];
            ++idim_out;
        }
    }
}
