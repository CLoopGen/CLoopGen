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

int ndim;
npy_intp *strides;
npy_stride_sort_item *out_strideperm;
int i;

void init_vars() {
    ndim = 1 << 20;  // Approximately 1M dimensions to target ~0.01s runtime
    strides = (npy_intp *)malloc(ndim * sizeof(npy_intp));
    out_strideperm = (npy_stride_sort_item *)malloc(ndim * sizeof(npy_stride_sort_item));

    for (i = 0; i < ndim; ++i) {
        strides[i] = (npy_intp)(i * 32);  // Arbitrary non-zero stride values
    }
}