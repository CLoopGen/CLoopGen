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
    // Variant 1: Consecutive memory access pattern using a flattened index
    npy_intp total_lower = 0;
    npy_intp total_upper = 0;
    for (i = 0; i < nd; i++) {
        if (dims[i] == 0) {
            *lower_offset = 0;
            *upper_offset = 0;
            return;
        }
        // Access in increasing dimension order with stride applied consecutively
        npy_intp axis_offset = strides[i] * (dims[i] - 1);
        if (axis_offset > 0) {
            total_upper += axis_offset;
        } else {
            total_lower += axis_offset;
        }
    }
    lower = total_lower;
    upper = total_upper;
}
