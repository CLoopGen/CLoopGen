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
    for (npy_intp i = 0; i < N; i += 2) {
        if (i + 1 < N) {
            *(double *)(out + strides[2] * 0) = *(double *)(in1 + strides[0] * 0) * *(double *)(in2 + strides[1] * 0);
            *(double *)(out + strides[2] * 1) = *(double *)(in1 + strides[0] * 1) * *(double *)(in2 + strides[1] * 1);
        } else {
            *(double *)out = *(double *)in1 * *(double *)in2;
        }
        in1 += 2 * strides[0];
        in2 += 2 * strides[1];
        out += 2 * strides[2];
    }
}
