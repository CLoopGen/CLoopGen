#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

int ndim;
npy_intp *out_shape;
npy_intp *out_strides;
int i;
int j;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB of data

void init_vars() {
    // Allocate large arrays to ensure loop takes measurable time
    out_shape = (npy_intp*)malloc(DATA_SIZE);
    out_strides = (npy_intp*)malloc(DATA_SIZE);
    
    if (!out_shape || !out_strides) {
        exit(1);
    }

    // Initialize ndim to a reasonable value within allocated bounds
    ndim = DATA_SIZE / (sizeof(npy_intp) * 2); // Use half the buffer for safety
    if (ndim > 1000000) ndim = 1000000; // Cap at 1M dimensions
    
    // Initialize array contents
    for (int idx = 0; idx < ndim; ++idx) {
        out_shape[idx] = (idx % 7 == 0) ? 1 : (2 + (idx % 15)); // Mix of 1s and other values
        out_strides[idx] = (npy_intp)(16 * (1 + idx % 1000));  // Varying stride values
    }
    
    // Ensure initial state for loop
    i = 0;
}