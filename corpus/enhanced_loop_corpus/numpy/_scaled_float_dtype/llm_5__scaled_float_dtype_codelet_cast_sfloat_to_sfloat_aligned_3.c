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
    for (npy_intp i = 0; i < N; i++) {
        double input_val = *(double *)in;
        if (input_val > 0) {
            *(double *)out = input_val * factor;
        } else {
            *(double *)out = 0.0;
        }
        in += strides[0];
        out += strides[1];
    }
}
