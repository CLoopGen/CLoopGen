#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

npy_intp strides[3];
npy_intp N;
char *in1;
char *in2;
char *out;

static double *in1_data;
static double *in2_data;
static double *out_data;

void init_vars() {
    // Estimate performance: assume ~1ns per iteration, so for 0.01s we need ~10M iterations
    // Adjust to get roughly 10-20 million elements for ~0.01 sec runtime
    N = 12500000;  // 12.5M doubles -> 100 MB total input (2 inputs + output)

    // Allocate aligned memory for input and output arrays
    posix_memalign((void**)&in1_data, 64, N * sizeof(double));
    posix_memalign((void**)&in2_data, 64, N * sizeof(double));
    posix_memalign((void**)&out_data, 64, N * sizeof(double));

    // Initialize data with non-zero values to allow compiler to optimize less
    for (npy_intp i = 0; i < N; i++) {
        in1_data[i] = 1.0 + (i % 7) * 0.1;
        in2_data[i] = 2.0 + (i % 11) * 0.1;
        out_data[i] = 0.0;
    }

    // Set base pointers
    in1 = (char*)in1_data;
    in2 = (char*)in2_data;
    out = (char*)out_data;

    // Set strides: contiguous double arrays
    strides[0] = sizeof(double);
    strides[1] = sizeof(double);
    strides[2] = sizeof(double);
}