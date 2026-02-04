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
    npy_intp i = 0;
    if (N > 0) {
        do {
            *(double *)out = *(double *)in1 * *(double *)in2;
            in1 += strides[0];
            in2 += strides[1];
            out += strides[2];
            i++;
        } while (i < N);
    }
}
