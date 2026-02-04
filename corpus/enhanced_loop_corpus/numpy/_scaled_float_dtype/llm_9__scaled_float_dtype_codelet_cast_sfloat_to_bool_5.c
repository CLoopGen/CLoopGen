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
    npy_intp i;
    for (i = 0; i < N; i++) {
        double val = *(double *)in;
        *(npy_bool *)out = (val != 0.0) && (val * val > 1e-10);
        in += strides[0];
        out += strides[1];
    }
}
