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
    npy_intp j, i;
    nitems = 1;
    for (j = 0; j < ndim; j++) {
        for (i = 0; i < 1; i++) {
            nitems *= shape_it[j];
        }
    }
}
