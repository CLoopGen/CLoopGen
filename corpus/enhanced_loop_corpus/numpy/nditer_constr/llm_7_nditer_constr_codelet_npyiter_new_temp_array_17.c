#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int op_ndim;
extern npy_intp strides[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp base_val = 9223372036854775807L;
    strides[0] = base_val;
    for (i = 1; i < op_ndim; ++i) {
        strides[i] = strides[i - 1]; // Introduce loop-carried WAW dependency
    }
}
