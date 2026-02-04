#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef signed char npy_int8;

int axis;
int idim;
int ndim;
int xdim;
npy_int8 *perm;

void init_vars() {
    ndim = 10000000;  
    xdim = ndim / 2;
    axis = ndim / 4;

    perm = (npy_int8*)aligned_alloc(32, ndim * sizeof(npy_int8));
    if (!perm) {
        exit(1);
    }

    for (int i = 0; i < ndim; ++i) {
        if (i < xdim) {
            perm[i] = (npy_int8)(i % 127);
        } else {
            perm[i] = (npy_int8)((i + 1) % 127);
        }
    }
}