#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

int ndim;
npy_intp shape_it[64];
npy_intp nitems;
npy_intp i;

void init_vars() {
    // Set number of dimensions to a reasonable value (e.g., 3)
    ndim = 3;

    // Set shape to create total size around 1MB - 256MB worth of "items"
    // We aim for nitems after multiplication to be roughly in that range
    // Start with nitems = 1 and multiply by shapes
    nitems = 1;
    
    // Choose shape values so that product is about 10^7 to 10^8 elements
    // For example: 400 x 400 x 400 = 64,000,000 (~64 million)
    shape_it[0] = 400;
    shape_it[1] = 400;
    shape_it[2] = 400;

    // Initialize remaining dimensions to 1 (unused)
    for (int j = 3; j < 64; j++) {
        shape_it[j] = 1;
    }

    // Reset nitems to 1 before loop use (since loop does *=)
    nitems = 1;

    // Ensure i is initialized properly before use in other contexts
    i = 0;
}