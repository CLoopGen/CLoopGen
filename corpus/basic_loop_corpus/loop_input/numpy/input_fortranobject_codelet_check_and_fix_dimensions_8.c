#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

int rank = 4;
npy_intp *dims;
int i;
npy_intp size;

void init_vars() {
    dims = (npy_intp*)malloc(rank * sizeof(npy_intp));
    if (!dims) {
        exit(1);
    }
    dims[0] = 64;
    dims[1] = 64;
    dims[2] = 64;
    dims[3] = 1;
}