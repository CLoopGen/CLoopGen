#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char npy_bool;

int ndim;
npy_bool *axis_flags;
int idim;
int naxes;

void init_vars() {
    ndim = 1 << 20; // Approximately 1 million dimensions
    axis_flags = (npy_bool*)calloc(ndim, sizeof(npy_bool));
    if (!axis_flags) {
        exit(1);
    }

    // Randomly set about half of the flags to true
    for (int i = 0; i < ndim; i += 2) {
        axis_flags[i] = 1;
    }

    naxes = 0;
}