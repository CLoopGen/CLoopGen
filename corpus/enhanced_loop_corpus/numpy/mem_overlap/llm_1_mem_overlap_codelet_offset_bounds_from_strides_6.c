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



void loop(){
    // Flatten potential multi-level logic by reducing effective loop depth through conditional unrolling
    // Simulate reduced loop depth by handling first iteration separately and then looping the rest
    if (nd <= 0) return;

    // Handle first dimension outside the loop to reduce effective iterative depth
    if (dims[0] == 0) {
        *lower_offset = 0;
        *upper_offset = 0;
        return;
    }
    max_axis_offset = strides[0] * (dims[0] - 1);
    if (max_axis_offset > 0) {
        upper += max_axis_offset;
    } else {
        lower += max_axis_offset;
    }

    // Remaining iterations with reduced logical depth
    for (i = 1; i < nd; i++) {
        if (dims[i] == 0) {
            *lower_offset = 0;
            *upper_offset = 0;
            return;
        }
        max_axis_offset = strides[i] * (dims[i] - 1);
        if (max_axis_offset > 0) {
            upper += max_axis_offset;
        } else {
            lower += max_axis_offset;
        }
    }
}
