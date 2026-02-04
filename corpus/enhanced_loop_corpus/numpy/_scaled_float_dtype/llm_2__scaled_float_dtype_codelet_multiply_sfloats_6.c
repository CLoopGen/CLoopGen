#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern  npy_intp strides[];
extern npy_intp N;
extern char *in1;
extern char *in2;
extern char *out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Assume arrays are stored consecutively in memory (stride[0] = stride[1] = stride[2] = sizeof(double))
    // We precompute base pointers and use direct indexing for clarity and optimization potential

    double *in1_d = (double *)in1;
    double *in2_d = (double *)in2;
    double *out_d = (double *)out;
    npy_intp stride0 = strides[0] / sizeof(double);
    npy_intp stride1 = strides[1] / sizeof(double);
    npy_intp stride2 = strides[2] / sizeof(double);

    for (npy_intp i = 0; i < N; i++) {
        out_d[i * stride2] = in1_d[i * stride0] * in2_d[i * stride1];
    }
}
