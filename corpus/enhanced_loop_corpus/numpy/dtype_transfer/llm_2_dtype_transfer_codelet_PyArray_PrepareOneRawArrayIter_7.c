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
    // Variant 1: Consecutive memory access pattern using pointer arithmetic
    npy_intp *shape_ptr = out_shape;
    npy_intp *strides_ptr = out_strides;
    npy_intp current_shape = shape_ptr[i];
    npy_intp current_stride = strides_ptr[i];

    for (j = 1; j < ndim; ++j) {
        if (current_shape == 1) {
            current_shape = shape_ptr[j];
            current_stride = strides_ptr[j];
        } else if (shape_ptr[j] == 1) {
            continue;
        } else if (current_stride * current_shape == strides_ptr[j]) {
            current_shape *= shape_ptr[j];
        } else {
            ++i;
            shape_ptr[i] = shape_ptr[j];
            strides_ptr[i] = strides_ptr[j];
            current_shape = shape_ptr[j];
            current_stride = strides_ptr[j];
        }
    }
    // Update the original arrays through pointers (if needed)
    out_shape[i] = current_shape;
    out_strides[i] = current_stride;
}
