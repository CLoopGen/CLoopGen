#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

int idim;
int broadcast_ndim = 32;
npy_intp iter_shape[32];

void init_vars() {
    idim = 0;
}