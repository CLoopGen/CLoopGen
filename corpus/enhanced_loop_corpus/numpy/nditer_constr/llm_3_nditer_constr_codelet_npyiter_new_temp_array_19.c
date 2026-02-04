#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int op_ndim;
extern npy_intp strides[64];
extern int i;
extern npy_intp factor;
extern npy_intp new_strides[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reverse traversal with strided memory access: process every other dimension
    for (i = op_ndim - 1; i >= 0; i -= 2) {
        if (strides[i] == 9223372036854775807L) {
            strides[i] = new_strides[i];
        } else {
            strides[i] *= factor;
        }
        // Ensure forward progress when stepping by 2
        if (i == 0) break;
    }
    // Handle odd-sized op_ndim by processing skipped indices in a second forward pass
    for (i = 1; i < op_ndim; i += 2) {
        if (strides[i] == 9223372036854775807L) {
            strides[i] = new_strides[i];
        } else {
            strides[i] *= factor;
        }
    }
}
