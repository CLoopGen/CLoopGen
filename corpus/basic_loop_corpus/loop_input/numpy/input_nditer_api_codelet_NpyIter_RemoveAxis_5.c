#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

int iop = 0;
int nop = 131072; // Approximately 1MB of data (131072 * sizeof(npy_intp) ≈ 1MB if npy_intp is 8 bytes)
npy_intp *strides = NULL;

void init_vars() {
    strides = (npy_intp *)calloc(nop, sizeof(npy_intp));
    if (!strides) {
        exit(1);
    }
}