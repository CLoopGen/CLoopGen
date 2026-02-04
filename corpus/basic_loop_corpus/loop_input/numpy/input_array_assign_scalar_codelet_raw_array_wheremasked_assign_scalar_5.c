#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

int ndim;
npy_intp shape_it[64];
npy_intp nitems;
npy_intp i;

void init_vars() {
    // Set dimensions to achieve approximately 0.01 seconds runtime
    // Use moderate number of dimensions and product to get into millions of items range
    ndim = 4;
    shape_it[0] = 100;
    shape_it[1] = 100;
    shape_it[2] = 100;
    shape_it[3] = 10;
    nitems = 1; // Initial value before loop multiplication
}