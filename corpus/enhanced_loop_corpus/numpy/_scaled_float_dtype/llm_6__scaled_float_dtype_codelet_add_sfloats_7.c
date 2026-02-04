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
    double temp1, temp2;
    for (npy_intp i = 0; i < N; i++) {
        temp1 = (*(double *)in1) * fact1;
        temp2 = (*(double *)in2) * fact2;
        *(double *)out = temp1 + temp2;
        in1 += strides[0];
        in2 += strides[1];
        out += strides[2];
    }
}
