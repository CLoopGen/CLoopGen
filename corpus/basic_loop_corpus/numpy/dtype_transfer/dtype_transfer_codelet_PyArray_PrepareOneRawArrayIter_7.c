#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int ndim;
extern npy_intp *out_shape;
extern npy_intp *out_strides;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (j = 1; j < ndim; ++j) {
    if (out_shape[i] == 1) {
        out_shape[i] = out_shape[j];
        out_strides[i] = out_strides[j];
    } else if (out_shape[j] == 1) {
    } else if (out_strides[i] * out_shape[i] == out_strides[j]) {
        out_shape[i] *= out_shape[j];
    } else {
        ++i;
        out_shape[i] = out_shape[j];
        out_strides[i] = out_strides[j];
    }
}

}
