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
    for (i = 0; i < op_ndim; ++i) {
        strides[i] = (strides[i] == 9223372036854775807L) ? new_strides[i] : strides[i] * factor;
    }
}
