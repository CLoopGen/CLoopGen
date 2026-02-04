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
    for (nk = nj - 1; nk > ni; nk--) {
        if (newdims[nk] <= 0) continue;
        newstrides[nk - 1] = newstrides[nk] * newdims[nk];
    }
}
