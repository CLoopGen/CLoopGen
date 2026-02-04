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
    for (idim = 0; idim < ndim; ++idim) {
        if (flags[idim] == 0) {
            shape[idim_out] = shape[idim];
            strides[idim_out] = strides[idim];
            idim_out++;
        }
    }
}
