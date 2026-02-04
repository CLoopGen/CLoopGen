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
    double acc = 1.0;
    for (npy_intp i = 0; i < N; i++) {
        double val = *(double *)in * factor;
        acc *= val; // Introduce loop-carried dependency (WAW on `acc`)
        *(double *)out = val;
        in += strides[0];
        out += strides[1];
    }
    // Prevent unused variable optimization; assume side effect
    *(volatile double *)out = acc;
}
