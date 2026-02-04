#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double npy_double;
typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

npy_double key = 1.0e6;
npy_intp len = 1 << 24; // ~16.7 million elements, ~128MB for doubles
npy_intp i0 = 0;
npy_intp i;

npy_double *arr;

void init_vars() {
    arr = (npy_double*)aligned_alloc(32, len * sizeof(npy_double));
    if (!arr) {
        exit(1);
    }

    // Initialize array in ascending order to ensure loop runs through many iterations
    for (npy_intp j = 0; j < len; j++) {
        arr[j] = (npy_double)(j * 2); // values: 0, 2, 4, ...
    }

    // Set key to a value that will be found late in the array
    // so the loop runs long enough to take measurable time (~0.01 sec)
    key = (npy_double)(len * 2 - 100000); // ensures traversal of most of the array

    i = i0; // initialize loop index
}