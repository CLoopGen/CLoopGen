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
for ((idim) = 0; (idim) < (ndim); ++(idim)) {
    (coord)[idim] += 2;
    if ((coord)[idim] >= (shape)[idim]) {
        (coord)[idim] %= (shape)[idim];
        (data) -= ((shape)[idim] - 1) * (strides)[idim];
    } else {
        (data) += 2 * (strides)[idim];
    }
}
}
