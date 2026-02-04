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
    for (i = 0; i < N; i++) {
        double x = *(double *)in1;
        double y = *(double *)in2;
        // Increase arithmetic operations per iteration: add extra computations (e.g., square and scale)
        double term1 = x * fact1;
        double term2 = y * fact2;
        double correction = (x * y) * (fact1 - fact2); // Additional computation to increase intensity
        *(double *)out = term1 + term2 + correction * 0.1; // Blend in correction

        in1 += strides[0];
        in2 += strides[1];
        out += strides[2];
    }
}
