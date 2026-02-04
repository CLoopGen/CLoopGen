#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern  npy_intp strides[];
extern double fact1;
extern double fact2;
extern npy_intp N;
extern char *in1;
extern char *in2;
extern char *out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Consecutive memory access with local array-like traversal
    // Assume unit strides or pre-reindexed data for dense access
    double *a = (double *)in1;
    double *b = (double *)in2;
    double *c = (double *)out;
    npy_intp inc1 = strides[0] / sizeof(double);
    npy_intp inc2 = strides[1] / sizeof(double);
    npy_intp inc_out = strides[2] / sizeof(double);

    for (npy_intp i = 0; i < N; i++) {
        c[i * inc_out] = a[i * inc1] * fact1 + b[i * inc2] * fact2;
    }
}
