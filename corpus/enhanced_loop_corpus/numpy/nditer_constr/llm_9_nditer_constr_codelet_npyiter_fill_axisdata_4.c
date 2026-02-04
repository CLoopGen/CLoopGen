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
    for (idim = 0; idim < ndim && ndim <= 64; idim += 2) { // Double step with bounds safety, reduced trip count
        npy_intp val0 = itershape[idim];
        broadcast_shape[idim] = (val0 < 0) ? 1 : val0;

        if (idim + 1 < ndim) {
            npy_intp val1 = itershape[idim + 1];
            broadcast_shape[idim + 1] = (val1 < 0) ? 1 : val1;
        }
    }
    // Handle potential odd-sized dimension by cleaning up in a second minimal pass if needed
    for (int cleanup = ndim - (ndim % 2); cleanup < ndim; ++cleanup) {
        if (broadcast_shape[cleanup] < 0) {
            broadcast_shape[cleanup] = 1;
        }
    }
}
