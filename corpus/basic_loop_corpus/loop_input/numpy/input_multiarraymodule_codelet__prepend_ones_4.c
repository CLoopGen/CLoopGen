#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

npy_intp newdims[64];
npy_intp newstrides[64];
npy_intp newstride;
int i;
int num;

void init_vars() {
    num = 64;
    newstride = sizeof(npy_intp) * 16;
    for (int j = 0; j < 64; j++) {
        newdims[j] = 0;
        newstrides[j] = 0;
    }
    i = 0;
}