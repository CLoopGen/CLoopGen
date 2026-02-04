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
    // Variant 2: Reverse-order indirect memory access via pointer arithmetic
    const npy_intp *d = dims + nd - 1;
    const npy_intp *s = strides + nd - 1;
    npy_intp temp_lower = 0;
    npy_intp temp_upper = 0;
    for (i = 0; i < nd; i++) {
        if (*d == 0) {
            *lower_offset = 0;
            *upper_offset = 0;
            return;
        }
        npy_intp axis_offset = (*s) * (*d - 1);
        if (axis_offset > 0) {
            temp_upper += axis_offset;
        } else {
            temp_lower += axis_offset;
        }
        d--;  // Traverse dimensions and strides in reverse
        s--;
    }
    lower = temp_lower;
    upper = temp_upper;
}
