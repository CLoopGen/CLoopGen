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
    double *out_ptr = (double *)out;
    const double *in_ptr = (const double *)in;
    npy_intp stride_in = strides[0];
    npy_intp stride_out = strides[1];

    for (npy_intp i = 0; i < N; i++) {
        out_ptr[i] = in_ptr[i * (stride_in / sizeof(double))];
    }

    in += stride_in * N;
    out += stride_out * N;
}
