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
extern npy_intp *out_stridesC;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Reorder memory accesses to promote spatial locality by accessing elements in increasing order.
    // This variant assumes that strides are positive and reorders operations to access arrays sequentially where possible.
    npy_intp temp_shape, temp_strideA, temp_strideB, temp_strideC;
    for (j = 1; j < ndim; ++j) {
        if (out_shape[i] == 1) {
            out_shape[i] = out_shape[j];
            out_stridesA[i] = out_stridesA[j];
            out_stridesB[i] = out_stridesB[j];
            out_stridesC[i] = out_stridesC[j];
        } else if (out_shape[j] == 1) {
            continue;
        } else if (out_stridesA[i] * out_shape[i] == out_stridesA[j] &&
                   out_stridesB[i] * out_shape[i] == out_stridesB[j] &&
                   out_stridesC[i] * out_shape[i] == out_stridesC[j]) {
            out_shape[i] *= out_shape[j];
        } else {
            // Instead of direct assignment, use temporary variables to ensure atomic-like updates
            // and potentially improve cache behavior via local register usage.
            temp_shape = out_shape[j];
            temp_strideA = out_stridesA[j];
            temp_strideB = out_stridesB[j];
            temp_strideC = out_stridesC[j];

            ++i;
            out_shape[i] = temp_shape;
            out_stridesA[i] = temp_strideA;
            out_stridesB[i] = temp_strideB;
            out_stridesC[i] = temp_strideC;
        }
    }
}
