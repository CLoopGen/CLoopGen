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
    npy_intp i, k;
    nitems = 1;
    for (k = 0; k < 1; k++) {
        for (i = 0; i < ndim; i++) {
            nitems *= shape_it[i];
        }
    }
}
