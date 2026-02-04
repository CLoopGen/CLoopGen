#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern  npy_intp strides[];
extern double fact1;
extern double fact2;
extern npy_intp N;
extern char *in1;
extern char *in2;
extern char *out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double acc = 0.0;
    char *in1_local = in1;
    char *in2_local = in2;
    for (npy_intp i = 0; i < N; i++) {
        acc += (*(double *)in1_local) * fact1 + (*(double *)in2_local) * fact2;
        in1_local += strides[0];
        in2_local += strides[1];
    }
    *(double *)out = acc;
    out += strides[2];
}
