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
    double prev_out = 0.0;
    for (npy_intp i = 0; i < N; i++) {
        double current_in1 = *(double *)in1;
        double current_in2 = *(double *)in2;
        double result = current_in1 * current_in2 + prev_out;
        *(double *)out = result;
        prev_out = result;
        in1 += strides[0];
        in2 += strides[1];
        out += strides[2];
    }
}
