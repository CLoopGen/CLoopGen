#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern  npy_intp strides[];
extern npy_intp N;
extern char *in;
extern char *out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access (unit stride)
    // Assume data is densely packed; remove striding and access elements consecutively
    double *in_d = (double *)in;
    double *out_d = (double *)out;
    for (npy_intp i = 0; i < N; i++) {
        out_d[i] = in_d[i];
    }
}
