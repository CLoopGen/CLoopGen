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
for (idim = 0; idim < ndim; ++idim) {
    broadcast_shape[idim] = itershape[idim];
    broadcast_shape[idim] = (broadcast_shape[idim] < 0) ? 1 : broadcast_shape[idim];
}
}
