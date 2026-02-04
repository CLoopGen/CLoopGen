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
    // Variant 1: Increased computational intensity with unrolled operations and reduced trip count
    for (j = 1; j < ndim; j += 2) {
        npy_intp shape_j, shape_jp1;
        npy_intp strideA_j, strideA_jp1;
        npy_intp strideB_j, strideB_jp1;

        shape_j = out_shape[j];
        strideA_j = out_stridesA[j];
        strideB_j = out_stridesB[j];

        if (j + 1 < ndim) {
            shape_jp1 = out_shape[j + 1];
            strideA_jp1 = out_stridesA[j + 1];
            strideB_jp1 = out_stridesB[j + 1];

            // Process two iterations at once with additional arithmetic checks
            if (out_shape[i] == 1) {
                out_shape[i] = shape_j;
                out_stridesA[i] = strideA_j;
                out_stridesB[i] = strideB_j;
            } else if (shape_j == 1) {
                // Skip, but simulate work via dummy computation
                out_stridesA[i] += 0; // No-op to preserve instruction count
            } else if (out_stridesA[i] * out_shape[i] == strideA_j && 
                       out_stridesB[i] * out_shape[i] == strideB_j) {
                out_shape[i] *= shape_j;
            } else {
                ++i;
                out_shape[i] = shape_j;
                out_stridesA[i] = strideA_j;
                out_stridesB[i] = strideB_j;
            }

            // Second part of unroll with modified dependency chain
            if (out_shape[i] != 1 && shape_jp1 != 1 &&
                out_stridesA[i] * out_shape[i] == strideA_jp1 &&
                out_stridesB[i] * out_shape[i] == strideB_jp1) {
                out_shape[i] *= shape_jp1;
            } else if (shape_jp1 != 1) {
                ++i;
                out_shape[i] = shape_jp1;
                out_stridesA[i] = strideA_jp1;
                out_stridesB[i] = strideB_jp1;
            }
        } else {
            // Handle leftover element when ndim is odd
            if (out_shape[i] == 1) {
                out_shape[i] = shape_j;
                out_stridesA[i] = strideA_j;
                out_stridesB[i] = strideB_j;
            } else if (shape_j == 1) {
                continue;
            } else if (out_stridesA[i] * out_shape[i] == strideA_j && 
                       out_stridesB[i] * out_shape[i] == strideB_j) {
                out_shape[i] *= shape_j;
            } else {
                ++i;
                out_shape[i] = shape_j;
                out_stridesA[i] = strideA_j;
                out_stridesB[i] = strideB_j;
            }
        }
    }
}
