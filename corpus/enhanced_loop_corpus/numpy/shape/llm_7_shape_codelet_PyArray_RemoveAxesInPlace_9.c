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
    npy_intp local_offset = 0;
    for (idim = 0; idim < ndim; ++idim) {
        if (!flags[idim]) {
            shape[idim_out + local_offset] = shape[idim];
            strides[idim_out + local_offset] = strides[idim];
            local_offset = (local_offset + 1) % 2;
        }
    }
    idim_out += (local_offset == 1) ? 1 : 0;
}
