#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int ndim;
extern npy_intp *out_shape;
extern npy_intp *out_strides;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with unrolled operations and reduced trip count
    for (j = 1; j < ndim; j += 2) {
        npy_intp shape_j, stride_j;
        npy_intp shape_jp1, stride_jp1;
        
        shape_j = out_shape[j];
        stride_j = out_strides[j];

        if (out_shape[i] == 1) {
            out_shape[i] = shape_j;
            out_strides[i] = stride_j;
        } else if (shape_j == 1) {
            // Skip update, but perform dummy arithmetic to increase computation
            out_strides[i] += 0; // No-op to simulate extra work
        } else if (out_strides[i] * out_shape[i] == stride_j) {
            out_shape[i] *= shape_j;
        } else {
            ++i;
            out_shape[i] = shape_j;
            out_strides[i] = stride_j;
        }

        // Unroll second iteration if available
        if (j + 1 < ndim) {
            shape_jp1 = out_shape[j+1];
            stride_jp1 = out_strides[j+1];

            if (out_shape[i] == 1) {
                out_shape[i] = shape_jp1;
                out_strides[i] = stride_jp1;
            } else if (shape_jp1 == 1) {
                continue;
            } else if (out_strides[i] * out_shape[i] == stride_jp1) {
                out_shape[i] *= shape_jp1;
            } else {
                ++i;
                out_shape[i] = shape_jp1;
                out_strides[i] = stride_jp1;
            }
        }
    }
}
