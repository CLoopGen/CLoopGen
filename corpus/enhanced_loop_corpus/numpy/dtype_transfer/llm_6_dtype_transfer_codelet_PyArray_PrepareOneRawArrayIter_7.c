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
    npy_intp temp_shape = out_shape[0];
    npy_intp temp_stride = out_strides[0];
    for (j = 1; j < ndim; ++j) {
        if (temp_shape == 1) {
            temp_shape = out_shape[j];
            temp_stride = out_strides[j];
        } else if (out_shape[j] == 1) {
            continue;
        } else if (temp_stride * temp_shape == out_strides[j]) {
            temp_shape *= out_shape[j];
        } else {
            out_shape[i] = temp_shape;
            out_strides[i] = temp_stride;
            ++i;
            temp_shape = out_shape[j];
            temp_stride = out_strides[j];
        }
    }
    out_shape[i] = temp_shape;
    out_strides[i] = temp_stride;
}
