#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int op_ndim;
extern npy_intp strides[64];
extern int i;
extern npy_intp factor;
extern npy_intp new_strides[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp temp_strides[64];
    for (i = 0; i < op_ndim; ++i) {
        temp_strides[i] = new_strides[i];
    }
    for (i = 0; i < op_ndim; ++i) {
        if (strides[i] == 9223372036854775807L) {
            strides[i] = temp_strides[i];
        } else {
            strides[i] *= factor;
        }
    }
}
