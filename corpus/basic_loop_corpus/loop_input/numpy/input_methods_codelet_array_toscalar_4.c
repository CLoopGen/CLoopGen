#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

npy_intp multi_index[64];
int idim;
int ndim;
npy_intp *shape;
npy_intp value;

void init_vars() {
    ndim = 8;
    value = 1000000;

    shape = (npy_intp *)malloc(ndim * sizeof(npy_intp));
    if (!shape) {
        exit(1);
    }

    for (int i = 0; i < ndim; ++i) {
        shape[i] = 10 + i;
    }

    for (int i = 0; i < 64; ++i) {
        multi_index[i] = 0;
    }
}