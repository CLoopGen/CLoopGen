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
    npy_bool temp_result;
    for (npy_intp i = 0; i < N; i++) {
        temp_result = *(double *)in != 0;
        in += strides[0];
        *(npy_bool *)out = temp_result;
        out += strides[1];
    }
}
