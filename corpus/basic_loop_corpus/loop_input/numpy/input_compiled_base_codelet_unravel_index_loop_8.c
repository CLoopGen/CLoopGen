#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

int unravel_ndim = 4;
npy_intp *unravel_dims = NULL;
npy_intp *coords = NULL;
int i;
int idx = 0;
int idx_step = 1;
npy_intp val = 123456789;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * (1UL << 20) / sizeof(npy_intp))

void init_vars() {
    unravel_dims = (npy_intp*)aligned_alloc(64, unravel_ndim * sizeof(npy_intp));
    coords = (npy_intp*)aligned_alloc(64, TOTAL_ELEMENTS * sizeof(npy_intp));

    if (!unravel_dims || !coords) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int d = 0; d < unravel_ndim; ++d) {
        unravel_dims[d] = (d + 2) * 100 + 1;
    }

    val = 123456789;
    idx = 0;
    idx_step = 1;
}