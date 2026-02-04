#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int op_ndim;
extern  npy_intp *shape;
extern npy_intp strides[64];
extern int i;
extern npy_intp factor;
extern npy_intp itemsize;
extern npy_intp new_strides[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp reverse_i;
    for (i = 0; i < op_ndim; ++i) {
        reverse_i = op_ndim - 1 - i;
        if (strides[reverse_i] == 9223372036854775807L) {
            new_strides[reverse_i] = factor * itemsize;
            factor *= shape[reverse_i];
        }
    }
}
