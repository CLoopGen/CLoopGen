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
    if (N > 0) {
        npy_intp i = 0;
        for (; i < N / 2; i++) {
            *(double *)out = *(double *)in * factor;
            in += strides[0];
            out += strides[1];
        }
        for (; i < N; i++) {
            *(double *)out = *(double *)in * factor;
            in += strides[0];
            out += strides[1];
        }
    }
}
