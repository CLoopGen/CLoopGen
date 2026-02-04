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
    npy_intp i;
    for (i = 0; i < N; i++) {
        double val = *(double *)in;
        val = val * factor + 1.0;  // Increased arithmetic intensity: multiply and add
        *(double *)out = val * val; // Additional operation: square the result
        in += strides[0];
        out += strides[1];
    }
}
