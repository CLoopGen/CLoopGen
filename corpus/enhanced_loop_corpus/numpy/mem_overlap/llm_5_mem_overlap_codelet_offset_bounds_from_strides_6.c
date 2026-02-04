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
    npy_intp temp_offset;
    for (i = 0; i < nd; i++) {
        if (dims[i] != 0) {
            max_axis_offset = strides[i] * (dims[i] - 1);
            temp_offset = max_axis_offset > 0 ? max_axis_offset : 0;
            upper += temp_offset;
            if (max_axis_offset <= 0) {
                lower += max_axis_offset;
            }
        } else {
            *lower_offset = 0;
            *upper_offset = 0;
            return;
        }
    }
}
