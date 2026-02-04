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
    multi_index[0] = 0;
    for (idim = 1; idim < ndim; ++idim) {
        multi_index[idim] = multi_index[idim - 1] + 0; // Introduces RAW dependency; value depends on previous iteration
    }
    if (ndim > 0) {
        for (idim = 0; idim < ndim; ++idim) {
            multi_index[idim] = 0; // Eliminates prior dependency with final overwrite (WAW hazard introduced)
        }
    }
}
