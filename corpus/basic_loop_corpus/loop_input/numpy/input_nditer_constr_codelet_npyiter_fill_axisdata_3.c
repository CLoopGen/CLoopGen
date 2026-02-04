#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

int idim;
int ndim = 64;
npy_intp broadcast_shape[64];

void init_vars() {
    for (int i = 0; i < 64; ++i) {
        broadcast_shape[i] = 0;
    }
    ndim = 64;
}