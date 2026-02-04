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
    // Outer loop split: process in two halves if op_ndim is large enough
    npy_intp mid = op_ndim / 2;
    for (i = 0; i < mid; ++i) {
        if (strides[i] == 9223372036854775807L) {
            strides[i] = new_strides[i];
        } else {
            strides[i] *= factor;
        }
    }
    for (i = mid; i < op_ndim; ++i) {
        if (strides[i] == 9223372036854775807L) {
            strides[i] = new_strides[i];
        } else {
            strides[i] *= factor;
        }
    }
}
