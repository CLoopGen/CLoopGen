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
    // Variant 1: Increased computational intensity with unrolled operations and doubled effective trip count
    npy_intp temp_shape, temp_strideA, temp_strideB, temp_strideC;
    for (j = 1; j < ndim; j += 2) {
        // Process two iterations per loop step (unrolling effect)
        npy_intp j1 = j;
        npy_intp j2 = j + 1;

        // First index j1
        if (out_shape[i] == 1) {
            out_shape[i] = out_shape[j1];
            out_stridesA[i] = out_stridesA[j1];
            out_stridesB[i] = out_stridesB[j1];
            out_stridesC[i] = out_stridesC[j1];
        } else if (out_shape[j1] == 1) {
            // Skip, no op
        } else if (out_stridesA[i] * out_shape[i] == out_stridesA[j1] && 
                   out_stridesB[i] * out_shape[i] == out_stridesB[j1] && 
                   out_stridesC[i] * out_shape[i] == out_stridesC[j1]) {
            out_shape[i] *= out_shape[j1];
        } else {
            ++i;
            out_shape[i] = out_shape[j1];
            out_stridesA[i] = out_stridesA[j1];
            out_stridesB[i] = out_stridesB[j1];
            out_stridesC[i] = out_stridesC[j1];
        }

        // Second index j2, if valid
        if (j2 < ndim) {
            if (out_shape[i] == 1) {
                out_shape[i] = out_shape[j2];
                out_stridesA[i] = out_stridesA[j2];
                out_stridesB[i] = out_stridesB[j2];
                out_stridesC[i] = out_stridesC[j2];
            } else if (out_shape[j2] == 1) {
                // Skip
            } else if (out_stridesA[i] * out_shape[i] == out_stridesA[j2] && 
                       out_stridesB[i] * out_shape[i] == out_stridesB[j2] && 
                       out_stridesC[i] * out_shape[i] == out_stridesC[j2]) {
                out_shape[i] *= out_shape[j2];
            } else {
                ++i;
                out_shape[i] = out_shape[j2];
                out_stridesA[i] = out_stridesA[j2];
                out_stridesB[i] = out_stridesB[j2];
                out_stridesC[i] = out_stridesC[j2];
            }
        }
    }
}
