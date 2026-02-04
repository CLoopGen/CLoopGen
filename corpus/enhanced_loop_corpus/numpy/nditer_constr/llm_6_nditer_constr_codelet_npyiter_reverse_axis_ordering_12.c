#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

typedef signed char npy_int8;

extern int ndim;
extern npy_intp i;
extern npy_int8 *perm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp j;
    for (j = 0; j < ndim; ++j) {
        perm[j] = (npy_int8)(ndim - 1 - j);
    }
}
