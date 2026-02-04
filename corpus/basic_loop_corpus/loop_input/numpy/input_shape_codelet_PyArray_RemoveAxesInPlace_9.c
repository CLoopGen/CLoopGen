#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char npy_bool;
typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

npy_bool *flags;
npy_intp *shape;
npy_intp *strides;
int idim;
int ndim;
int idim_out;

#define DATA_SIZE (128 * 1024 * 1024) // ~128MB total data size

void init_vars() {
    ndim = 100000; // Large enough to create measurable loop overhead
    flags = (npy_bool*)calloc(ndim, sizeof(npy_bool));
    shape = (npy_intp*)malloc(ndim * sizeof(npy_intp));
    strides = (npy_intp*)malloc(ndim * sizeof(npy_intp));

    for (int i = 0; i < ndim; ++i) {
        shape[i] = rand() % 1000 + 1;
        strides[i] = rand() % 500 + 1;
        flags[i] = (rand() % 3) == 0; // ~1/3 of dimensions are flagged (skip)
    }

    idim = 0;
    idim_out = 0;

    // Ensure output arrays have space: worst-case idim_out grows to ndim
    // Since we reuse the same buffers and only write within [0,ndim), no realloc needed
}