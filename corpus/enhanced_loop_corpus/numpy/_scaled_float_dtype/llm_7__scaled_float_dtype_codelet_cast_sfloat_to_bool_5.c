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
    npy_bool *out_ptr = (npy_bool *)out;
    char *in_ptr = in;
    npy_intp stride0 = strides[0];
    npy_intp stride1 = strides[1];
    npy_bool acc = 0;
    for (npy_intp i = 0; i < N; i++) {
        acc |= (*(double *)(in_ptr + i * stride0) != 0); 
        out_ptr[i * stride1] = acc;
    }
    *(npy_bool *)out = acc; 
}
