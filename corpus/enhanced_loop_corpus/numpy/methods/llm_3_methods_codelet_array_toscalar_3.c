#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern npy_intp multi_index[64];
extern int idim;
extern int ndim;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp indices[64];
    for (idim = 0; idim < ndim; ++idim) {
        indices[idim] = idim; // indirect index setup
    }
    for (idim = 0; idim < ndim; ++idim) {
        multi_index[indices[idim]] = 0;
    }
}
