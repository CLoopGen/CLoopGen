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
    npy_intp stride = ndim > 4 ? ndim / 4 : 1;
    for (idim = 0; idim < ndim; idim += stride) {
        for (npy_intp j = 0; j < stride && (idim + j) < ndim; ++j) {
            multi_index[idim + j] = idim + j;
        }
    }
}
