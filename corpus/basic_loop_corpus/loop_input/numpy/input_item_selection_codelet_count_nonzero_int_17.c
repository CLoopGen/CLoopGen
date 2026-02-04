#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

int ndim = 3;
char *data;
int idim;
npy_intp shape[64] = {128, 128, 128};
npy_intp strides[64] = {16384, 128, 1};
npy_intp coord[64] = {0, 0, 0};

void init_vars() {
    // Allocate approximately 2MB of data to ensure loop runs around 0.01 seconds
    data = (char *)calloc(1, 2097152);
    if (!data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize shape and strides for a 128x128x128 byte array (2MB)
    shape[0] = 128; shape[1] = 128; shape[2] = 128;
    strides[0] = 128 * 128; strides[1] = 128; strides[2] = 1;

    // Zero out coordinates
    for (int i = 0; i < ndim; i++) {
        coord[i] = 0;
    }

    idim = 0;
}