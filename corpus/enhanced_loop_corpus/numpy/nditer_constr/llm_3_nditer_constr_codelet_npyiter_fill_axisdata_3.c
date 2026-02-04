#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int idim;
extern int ndim;
extern npy_intp broadcast_shape[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access, processing every second element forward and backward fill
    // First pass: even indices
    for (idim = 0; idim < ndim; idim += 2) {
        broadcast_shape[idim] = 1;
    }
    // Second pass: odd indices
    for (idim = 1; idim < ndim; idim += 2) {
        broadcast_shape[idim] = 1;
    }
}
