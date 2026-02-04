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



void loop() {
    for ((idim) = 1; (idim) < (ndim); ++(idim)) {
        npy_intp next_coord = (coord)[idim] + 1;
        if (next_coord == (shape)[idim]) {
            (coord)[idim] = 0;
            (data) -= ((shape)[idim]) * (strides)[idim];
        } else {
            (coord)[idim] = next_coord;
            (data) += (strides)[idim];
            break;
        }
    }
}
