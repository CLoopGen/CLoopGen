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
    // Variant 1: Increased computational intensity with additional arithmetic operations and reduced trip count
    npy_intp step = 2;
    for (nk = nj - 2; nk > ni; nk -= step) {
        newstrides[nk - 1] = newstrides[nk] * newdims[nk] + newstrides[nk - 1];
        if (nk > ni + 1) {
            newstrides[nk - 2] = newstrides[nk - 1] * newdims[nk - 1] + newstrides[nk - 2];
        }
    }
}
