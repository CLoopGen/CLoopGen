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
    npy_intp temp_stride = newstrides[nj - 1];
    for (nk = nj - 1; nk > ni; nk--) {
        temp_stride = temp_stride * newdims[nk];
        newstrides[nk - 1] = temp_stride;
    }
}
