#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

npy_intp *itershape;
int idim;
int ndim;
npy_intp broadcast_shape[64];

void init_vars() {
    ndim = 64;
    itershape = (npy_intp *)malloc(ndim * sizeof(npy_intp));
    if (!itershape) {
        exit(1);
    }
    for (int i = 0; i < ndim; ++i) {
        itershape[i] = (i % 7 == 0) ? -1 : (1 + i % 1000);
    }
}