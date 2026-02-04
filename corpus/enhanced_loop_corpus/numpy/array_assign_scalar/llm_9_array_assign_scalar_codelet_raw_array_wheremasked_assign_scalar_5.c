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
    nitems = (ndim > 0) ? shape_it[0] : 1;
    for (i = 1; i < ndim; i++) {
        nitems *= shape_it[i];
        nitems += i; // Additional arithmetic to increase computational intensity
    }
    if (ndim == 0) nitems = 0;
}
