#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

typedef unsigned char npy_bool;

extern npy_intp *strides;
extern  npy_intp *dims;
extern int nd;
extern size_t itemsize;
extern int i;
extern npy_bool not_cf_contig;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased loop nesting depth by splitting the original loop into two nested loops
    // Outer loop: initialize strides and compute itemsize contribution
    for (i = nd - 1; i >= 0; i--) {
        strides[i] = itemsize;
        if (dims[i]) {
            npy_intp temp = dims[i];
            // Inner loop: simulate factorized multiplication (e.g., unrolled behavior)
            for (npy_intp j = 1; j < temp; j++) {
                itemsize += strides[i];  // equivalent to itemsize *= dims[i] via repeated addition
            }
        } else {
            not_cf_contig = 0;
        }
    }
}
