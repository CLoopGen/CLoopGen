#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern  npy_intp *newdims;
extern npy_intp *newstrides;
extern int ni;
extern int nj;
extern int nk;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — process every second element forward, then fill in gaps
    npy_intp step = 2;
    // First pass: strided access with step size 2
    for (nk = ni + 1; nk < nj; nk += step) {
        newstrides[nk] = newstrides[nk - 1] * newdims[nk - 1];
    }
    // Second pass: handle remaining odd/even indices if step caused skips
    for (nk = ni + 2; nk < nj; nk += step) {
        if (newstrides[nk] == 0) { // Assume 0 indicates uninitialized stride
            newstrides[nk] = newstrides[nk - 1] * newdims[nk - 1];
        }
    }
}
