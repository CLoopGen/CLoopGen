#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

int ndim = 1000000;
npy_intp *out_shape;
npy_intp *out_stridesA;
npy_intp *out_stridesB;
npy_intp *out_stridesC;
int i = 0;
int j;

void init_vars() {
    out_shape = (npy_intp*)malloc(ndim * sizeof(npy_intp));
    out_stridesA = (npy_intp*)malloc(ndim * sizeof(npy_intp));
    out_stridesB = (npy_intp*)malloc(ndim * sizeof(npy_intp));
    out_stridesC = (npy_intp*)malloc(ndim * sizeof(npy_intp));

    for (int idx = 0; idx < ndim; ++idx) {
        out_shape[idx] = (idx % 7) + 1;
        out_stridesA[idx] = (idx + 1) * 8;
        out_stridesB[idx] = (idx + 1) * 4;
        out_stridesC[idx] = (idx + 1) * 2;
    }

    i = 0;
}