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
    npy_intp i;
    for (i = 0; i < N; i += 2) {
        if (i + 1 < N) {
            // Process two iterations at once to increase computational intensity
            double *out1 = (double *)(out);
            double *out2 = (double *)(out + strides[2]);
            double val1_1 = (*(double *)in1) * fact1;
            double val1_2 = (*(double *)in2) * fact2;
            double val2_1 = (*(double *)(in1 + strides[0])) * fact1;
            double val2_2 = (*(double *)(in2 + strides[1])) * fact2;

            *out1 = val1_1 + val1_2;
            *out2 = val2_1 + val2_2;

            in1 += 2 * strides[0];
            in2 += 2 * strides[1];
            out += 2 * strides[2];
        } else {
            // Handle odd-sized N
            *(double *)out = (*(double *)in1 * fact1) + (*(double *)in2 * fact2);
        }
    }
}
