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
    npy_intp temp_shape;
    npy_intp temp_strides;
    for (idim = 0; idim < ndim; ++idim) {
        if (!flags[idim]) {
            temp_shape = shape[idim];
            temp_strides = strides[idim];
            shape[idim_out] = temp_shape;
            strides[idim_out] = temp_strides;
            ++idim_out;
        }
    }
}
