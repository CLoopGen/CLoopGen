#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

int nd = 4;
npy_intp *dims;
npy_intp *strides;
npy_intp *lower_offset;
npy_intp *upper_offset;
npy_intp max_axis_offset;
npy_intp lower;
npy_intp upper;
int i;

void init_vars() {
    // Allocate arrays with size based on nd
    dims = (npy_intp*)calloc(nd, sizeof(npy_intp));
    strides = (npy_intp*)calloc(nd, sizeof(npy_intp));
    lower_offset = (npy_intp*)malloc(sizeof(npy_intp));
    upper_offset = (npy_intp*)malloc(sizeof(npy_intp));

    // Initialize dimensions to create ~100MB of data (adjust as needed)
    // Total elements: product of dims
    // For benchmarking purposes, set up a 4D array with roughly 10^7 elements
    dims[0] = 200;
    dims[1] = 100;
    dims[2] = 50;
    dims[3] = 10;  // Total: 200*100*50*10 = 10,000,000 elements

    // Row-major strides
    strides[3] = 1;
    strides[2] = strides[3] * dims[3];
    strides[1] = strides[2] * dims[2];
    strides[0] = strides[1] * dims[1];

    // Scale strides to represent bytes (assuming 8-byte elements for ~80MB)
    for (int j = 0; j < nd; j++) {
        strides[j] *= 8;
    }

    // Initialize offset tracking variables
    *lower_offset = 0;
    *upper_offset = 0;
    lower = 0;
    upper = 0;
    max_axis_offset = 0;
    i = 0;
}