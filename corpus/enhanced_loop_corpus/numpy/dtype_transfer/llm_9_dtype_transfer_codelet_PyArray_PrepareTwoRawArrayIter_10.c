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
    // Variant 2: Reduced computational intensity with simplified conditions and increased trip count via split logic
    for (j = 1; j < ndim; ++j) {
        // Eliminate compound condition by splitting into simpler steps
        if (out_shape[i] == 1) {
            out_shape[i] = out_shape[j];
            out_stridesA[i] = out_stridesA[j];
            out_stridesB[i] = out_stridesB[j];
        } else if (out_shape[j] == 1) {
            // Explicitly skip; minimal operation
            continue;
        } else {
            // Separate each stride check to reduce arithmetic density
            npy_intp expected_strideA = out_stridesA[i] * out_shape[i];
            npy_intp actual_strideA = out_stridesA[j];
            npy_intp expected_strideB = out_stridesB[i] * out_shape[i];
            npy_intp actual_strideB = out_stridesB[j];

            if (expected_strideA == actual_strideA) {
                if (expected_strideB == actual_strideB) {
                    out_shape[i] *= out_shape[j];
                } else {
                    ++i;
                    out_shape[i] = out_shape[j];
                    out_stridesA[i] = out_stridesA[j];
                    out_stridesB[i] = out_stridesB[j];
                }
            } else {
                ++i;
                out_shape[i] = out_shape[j];
                out_stridesA[i] = out_stridesA[j];
                out_stridesB[i] = out_stridesB[j];
            }
        }
    }
}
