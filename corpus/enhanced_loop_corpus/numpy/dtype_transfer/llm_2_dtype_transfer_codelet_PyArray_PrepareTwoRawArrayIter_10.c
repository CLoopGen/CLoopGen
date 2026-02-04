#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int ndim;
extern npy_intp *out_shape;
extern npy_intp *out_stridesA;
extern npy_intp *out_stridesB;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Reorder memory accesses to favor consecutive strides by processing dimensions in reverse order.
    // This helps when higher dimensions have smaller strides, improving cache locality.

    for (j = ndim - 1; j >= 1; --j) {
        if (out_shape[i] == 1) {
            out_shape[i] = out_shape[j];
            out_stridesA[i] = out_stridesA[j];
            out_stridesB[i] = out_stridesB[j];
        } else if (out_shape[j] == 1) {
            continue;
        } else if (out_stridesA[i] * out_shape[i] == out_stridesA[j] && out_stridesB[i] * out_shape[i] == out_stridesB[j]) {
            out_shape[i] *= out_shape[j];
        } else {
            ++i;
            out_shape[i] = out_shape[j];
            out_stridesA[i] = out_stridesA[j];
            out_stridesB[i] = out_stridesB[j];
        }
    }
}
