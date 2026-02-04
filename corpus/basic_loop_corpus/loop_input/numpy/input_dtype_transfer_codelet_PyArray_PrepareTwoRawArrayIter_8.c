#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

typedef struct {
    npy_intp perm;
    npy_intp stride;
} npy_stride_sort_item;

int ndim = 64;

npy_intp *shape;
npy_intp *stridesA;
npy_intp *stridesB;
npy_intp *out_shape;
npy_intp *out_stridesA;
npy_intp *out_stridesB;
npy_stride_sort_item strideperm[64];

int i;

void init_vars() {
    shape = (npy_intp*)calloc(ndim, sizeof(npy_intp));
    stridesA = (npy_intp*)calloc(ndim, sizeof(npy_intp));
    stridesB = (npy_intp*)calloc(ndim, sizeof(npy_intp));
    out_shape = (npy_intp*)calloc(ndim, sizeof(npy_intp));
    out_stridesA = (npy_intp*)calloc(ndim, sizeof(npy_intp));
    out_stridesB = (npy_intp*)calloc(ndim, sizeof(npy_intp));

    for (int j = 0; j < ndim; ++j) {
        shape[j] = 1 + j % 5;
        stridesA[j] = (j + 1) * 8;
        stridesB[j] = (j + 1) * 4;
        strideperm[j].perm = ndim - j - 1;
        strideperm[j].stride = (ndim - j) * 16;
    }

    i = 0;
}