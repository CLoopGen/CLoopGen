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
    npy_intp temp_lower = lower;
    npy_intp temp_upper = upper;
    for (i = 0; i < nd; i++) {
        if (dims[i] == 0) {
            *lower_offset = 0;
            *upper_offset = 0;
            lower = temp_lower;
            upper = temp_upper;
            return;
        }
        max_axis_offset = strides[i] * (dims[i] - 1);
        if (max_axis_offset > 0) {
            temp_upper += max_axis_offset;
        } else {
            temp_lower += max_axis_offset;
        }
    }
    lower = temp_lower;
    upper = temp_upper;
}
