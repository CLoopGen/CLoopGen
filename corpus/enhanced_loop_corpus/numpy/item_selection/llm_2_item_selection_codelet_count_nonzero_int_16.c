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
    // Variant 1: Consecutive memory access by precomputing a flat offset
    npy_intp flat_stride = 0;
    for (idim = 1; idim < ndim; ++idim) {
        flat_stride += strides[idim];
        coord[idim]++;
        if (coord[idim] >= shape[idim]) {
            coord[idim] = 0;
            flat_stride -= shape[idim] * strides[idim];
        } else {
            data += flat_stride;
            break;
        }
    }
}
