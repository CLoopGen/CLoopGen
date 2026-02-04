#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

int ndim = 3;
char *data;
int idim;
npy_intp shape[64] = {1024, 512, 256};
npy_intp strides[64];
npy_intp coord[64] = {0};

void init_vars() {
    data = (char *)calloc(1, 1024 * 512 * 256);
    if (!data) exit(1);

    strides[0] = shape[1] * shape[2] * sizeof(char);
    strides[1] = shape[2] * sizeof(char);
    strides[2] = sizeof(char);

    for (int i = 0; i < ndim; ++i) {
        coord[i] = 0;
    }

    idim = 0;
}