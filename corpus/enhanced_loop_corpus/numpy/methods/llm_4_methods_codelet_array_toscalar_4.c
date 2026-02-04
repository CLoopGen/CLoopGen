#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern npy_intp multi_index[64];
extern int idim;
extern int ndim;
extern npy_intp *shape;
extern npy_intp value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (ndim <= 0) return;
    for (idim = ndim - 1; idim >= 0; --idim) {
        multi_index[idim] = value % shape[idim];
        value /= shape[idim];
    }
}
