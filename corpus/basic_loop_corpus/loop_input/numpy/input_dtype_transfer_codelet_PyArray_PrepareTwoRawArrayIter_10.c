#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

int ndim = 256000;
npy_intp *out_shape;
npy_intp *out_stridesA;
npy_intp *out_stridesB;
int i = 0;
int j;

void init_vars() {
    const size_t data_size = 256 * 1024; // ~256KB of index data (adjustable)
    ndim = data_size / sizeof(npy_intp);
    if (ndim < 2) ndim = 2;

    out_shape = (npy_intp*)aligned_alloc(64, ndim * sizeof(npy_intp));
    out_stridesA = (npy_intp*)aligned_alloc(64, ndim * sizeof(npy_intp));
    out_stridesB = (npy_intp*)aligned_alloc(64, ndim * sizeof(npy_intp));

    for (int idx = 0; idx < ndim; ++idx) {
        out_shape[idx] = (idx % 7 == 0) ? 1 : (2 + (idx % 5));
        out_stridesA[idx] = (npy_intp)(16 * (1 + idx % 8));
        out_stridesB[idx] = (npy_intp)(32 * (1 + idx % 6));
    }

    i = 0;
}