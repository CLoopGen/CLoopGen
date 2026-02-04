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
    npy_intp temp_strides[64];
    for (i = 0; i < op_ndim; ++i) {
        temp_strides[i] = 9223372036854775807L;
    }
    for (i = 0; i < op_ndim; ++i) {
        strides[i] = temp_strides[i];
    }
}
