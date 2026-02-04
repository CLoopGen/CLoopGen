#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int ndim;
extern npy_intp shape_it[64];
extern npy_intp nitems;
extern npy_intp i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    nitems = (ndim == 0) ? 1 : nitems;
    for (i = 0; i < ndim; i++) {
        if (shape_it[i] <= 0) continue;
        nitems *= shape_it[i];
    }
}
