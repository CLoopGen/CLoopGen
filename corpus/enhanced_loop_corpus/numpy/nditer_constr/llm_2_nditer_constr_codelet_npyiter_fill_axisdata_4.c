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
    npy_intp *shape_ptr = itershape;
    npy_intp *broadcast_ptr = broadcast_shape;
    for (idim = 0; idim < ndim; ++idim) {
        npy_intp val = *(shape_ptr + idim);
        *(broadcast_ptr + idim) = (val >= 0) ? val : 1;
    }
}
