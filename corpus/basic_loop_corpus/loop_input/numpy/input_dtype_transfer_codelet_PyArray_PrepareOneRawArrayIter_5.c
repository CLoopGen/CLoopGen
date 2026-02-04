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
npy_intp *strides;
npy_intp *out_shape;
npy_intp *out_strides;
npy_stride_sort_item strideperm[64];
int i;

void init_vars() {
    shape = (npy_intp*)aligned_alloc(64, sizeof(npy_intp) * ndim);
    strides = (npy_intp*)aligned_alloc(64, sizeof(npy_intp) * ndim);
    out_shape = (npy_intp*)aligned_alloc(64, sizeof(npy_intp) * ndim);
    out_strides = (npy_intp*)aligned_alloc(64, sizeof(npy_intp) * ndim);

    for (int j = 0; j < ndim; ++j) {
        shape[j] = (j + 1) * 10;
        strides[j] = (j + 1) * 8;
        strideperm[j].perm = ndim - j - 1;
        strideperm[j].stride = (j + 1) * 16;
        out_shape[j] = 0;
        out_strides[j] = 0;
    }
}