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
    npy_intp i;
    for (i = 0; i < N; i += 2) {
        if (i + 1 < N) {
            *(double *)out = *(double *)in;
            in += strides[0];
            out += strides[1];
            *(double *)out = *(double *)in;
            in += strides[0];
            out += strides[1];
        } else {
            *(double *)out = *(double *)in;
            in += strides[0];
            out += strides[1];
        }
    }
}
