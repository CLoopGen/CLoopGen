#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern npy_intp multi_index[64];
extern int idim;
extern int ndim;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (idim = 0; idim < ndim; ++idim) {
        if (ndim > 0) {
            multi_index[idim] = 0;
        }
    }
}
