#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int newnd;
extern npy_intp *newstrides;
extern npy_intp last_stride;
extern int ni;
extern int nk;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with increased inner operation density using unrolled-like behavior
    int limit = (ni + newnd) / 2;  // Halve effective iteration space
    for (nk = ni; nk < limit; nk++) {
        newstrides[nk]           = last_stride + nk;
        newstrides[newnd - 1 - (nk - ni)] = last_stride - nk;
        if (nk + 1 < limit) {
            newstrides[nk + 1] += last_stride / (nk + 1 + (last_stride != 0));
        }
        nk++; // Effectively process two elements per iteration
    }
}
