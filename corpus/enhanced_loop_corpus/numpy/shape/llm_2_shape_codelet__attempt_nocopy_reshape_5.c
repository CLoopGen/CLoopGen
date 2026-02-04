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
    // Variant 1: Consecutive memory access with reversed loop order (backward traversal)
    for (nk = nj - 1; nk > ni + 1; nk--) {
        newstrides[nk] = newstrides[nk - 1] * newdims[nk - 1];
    }
    // Handle the boundary case explicitly to maintain correctness
    if (nj > ni + 1) {
        newstrides[ni + 1] = newstrides[ni] * newdims[ni];
    }
}
