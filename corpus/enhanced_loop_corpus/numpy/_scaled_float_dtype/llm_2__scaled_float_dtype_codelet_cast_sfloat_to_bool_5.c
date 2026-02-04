#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

typedef unsigned char npy_bool;

extern  npy_intp strides[];
extern npy_intp N;
extern char *in;
extern char *out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp stride_in = strides[0];
    npy_intp stride_out = strides[1];
    char *in_ptr = in;
    char *out_ptr = out;
    for (npy_intp i = 0; i < N; i++) {
        *(npy_bool *)(out_ptr + i * stride_out) = *(double *)(in_ptr + i * stride_in) != 0;
    }
}
