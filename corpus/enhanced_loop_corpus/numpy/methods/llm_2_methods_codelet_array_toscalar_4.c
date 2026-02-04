#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern npy_intp multi_index[64];
extern int idim;
extern int ndim;
extern npy_intp *shape;
extern npy_intp value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reversing iteration order and accessing shape in forward order
    // We traverse dimensions from 0 to ndim-1 but compute multi_index using reversed logic
    npy_intp temp_value = value;
    for (idim = 0; idim < ndim; ++idim) {
        int rev_idim = ndim - 1 - idim;
        multi_index[rev_idim] = temp_value % shape[rev_idim];
        temp_value /= shape[rev_idim];
    }
}
