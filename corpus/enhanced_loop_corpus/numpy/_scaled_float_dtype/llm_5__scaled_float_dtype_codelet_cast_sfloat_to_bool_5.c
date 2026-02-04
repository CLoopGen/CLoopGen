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
    for (npy_intp i = 0; i < N; i++) {
        if ((*(double *)in) == 0.0) {
            *(npy_bool *)out = 0;
        } else {
            *(npy_bool *)out = 1;
        }
        in += strides[0];
        out += strides[1];
    }
}
