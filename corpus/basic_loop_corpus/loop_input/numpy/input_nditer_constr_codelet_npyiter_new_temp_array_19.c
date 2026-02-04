#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

int op_ndim = 64;
npy_intp strides[64];
int i;
npy_intp factor = 2;
npy_intp new_strides[64];

void init_vars() {
    for (int j = 0; j < 64; ++j) {
        if (j % 7 == 0) {
            strides[j] = 9223372036854775807LL;
        } else {
            strides[j] = (npy_intp)(1024 + j);
        }
        new_strides[j] = (npy_intp)(2048 + j);
    }
}