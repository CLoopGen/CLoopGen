#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern  npy_intp strides[];
extern double factor;
extern npy_intp N;
extern char *in;
extern char *out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by factor of 2
    npy_intp i = 0;
    char *in_ptr = in;
    char *out_ptr = out;
    npy_intp stride_in = strides[0];
    npy_intp stride_out = strides[1];

    // Process two elements per iteration when possible
    for (; i < N - 1; i += 2) {
        *(double *)out_ptr = *(double *)in_ptr * factor;
        in_ptr += stride_in;
        out_ptr += stride_out;

        *(double *)out_ptr = *(double *)in_ptr * factor;
        in_ptr += stride_in;
        out_ptr += stride_out;
    }

    // Handle remaining element if N is odd
    if (i < N) {
        *(double *)out_ptr = *(double *)in_ptr * factor;
    }
}
