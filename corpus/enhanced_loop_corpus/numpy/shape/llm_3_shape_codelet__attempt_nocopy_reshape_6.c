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
    // Variant 2: Strided memory access with step size of 2 to simulate non-unit stride traversal
    for (nk = nj - 1; nk > ni; nk -= 2) {
        if (nk - 1 > ni) { // Ensure we don't overwrite valid range
            newstrides[nk - 2] = newstrides[nk] * newdims[nk];
        }
        if (nk - 1 > ni) {
            newstrides[nk - 1] = newstrides[nk] * newdims[nk];
        }
    }
}
