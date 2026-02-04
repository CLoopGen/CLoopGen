#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern  int nd;
extern  npy_intp *dims;
extern  npy_intp *strides;
extern npy_intp *lower_offset;
extern npy_intp *upper_offset;
extern npy_intp max_axis_offset;
extern npy_intp lower;
extern npy_intp upper;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    npy_intp temp_lower = 0;
    npy_intp temp_upper = 0;
    npy_intp stride, dim;
    for (i = 0; i < nd; i++) {
        dim = dims[i];
        if (dim == 0) {
            *lower_offset = 0;
            *upper_offset = 0;
            return;
        }
        stride = strides[i];
        max_axis_offset = stride * (dim - 1);
        temp_lower += (max_axis_offset < 0) ? max_axis_offset : 0;
        temp_upper += (max_axis_offset > 0) ? max_axis_offset : 0;
    }
    lower = temp_lower;
    upper = temp_upper;
}
