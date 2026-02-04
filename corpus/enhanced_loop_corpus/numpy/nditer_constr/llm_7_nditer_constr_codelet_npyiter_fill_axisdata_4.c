#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern  npy_intp *itershape;
extern int idim;
extern int ndim;
extern npy_intp broadcast_shape[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp local_val;
    for (idim = 0; idim < ndim; ++idim) {
        local_val = itershape[idim];
        if (local_val < 0) {
            broadcast_shape[idim] = 1;
        } else {
            broadcast_shape[idim] = local_val;
        }
    }
}
