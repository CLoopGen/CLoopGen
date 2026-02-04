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
    npy_intp local_strides[64];
    npy_intp accumulated_factor = factor;
    for (i = op_ndim - 1; i >= 0; --i) {
        local_strides[i] = new_strides[i];
    }
    for (i = op_ndim - 1; i >= 0; --i) {
        if (strides[i] == 9223372036854775807L) {
            local_strides[i] = accumulated_factor * itemsize;
            accumulated_factor *= shape[i];
        }
    }
    for (i = op_ndim - 1; i >= 0; --i) {
        new_strides[i] = local_strides[i];
    }
    factor = accumulated_factor;
}
