#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

int op_ndim;
npy_intp strides[64];
int i;

void init_vars() {
    op_ndim = 64;
}