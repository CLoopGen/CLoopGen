#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern npy_intp i;
extern npy_intp n;
extern char *in1;
extern char *in2;
extern npy_intp in1_step;
extern npy_intp in2_step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (unrolled by factor of 2)
    npy_intp limit = n - (n % 2);
    for (i = 0; i < limit; i += 2) {
        (*(npy_intp *)in1) = *(npy_intp *)in1 + *(npy_intp *)in2;
        in1 += in1_step;
        in2 += in2_step;
        (*(npy_intp *)in1) = *(npy_intp *)in1 + *(npy_intp *)in2;
        in1 += in1_step;
        in2 += in2_step;
    }
    // Handle remaining element if n is odd
    for (; i < n; i++) {
        (*(npy_intp *)in1) = *(npy_intp *)in1 + *(npy_intp *)in2;
        in1 += in1_step;
        in2 += in2_step;
    }
}
