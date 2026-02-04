#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;
typedef unsigned char npy_bool;

npy_intp *strides;
npy_intp *dims;
int nd = 5;
size_t itemsize = 1;
int i;
npy_bool not_cf_contig;

void init_vars() {
    const size_t total_data_size = 64 * 1024 * 1024; // 64 MB target for ~0.01 sec on modern CPU
    size_t current_size = 1;

    // Choose dimensions such that total elements is around total_data_size / sizeof(item)
    // Assume base itemsize will grow multiplicatively, starting at 1
    nd = 5;
    dims = (npy_intp*)calloc(nd, sizeof(npy_intp));
    strides = (npy_intp*)calloc(nd, sizeof(npy_intp));

    // Set dims to create a large enough array: e.g., [100, 100, 100, 10, 10] -> 10^7 elements
    dims[0] = 100;
    dims[1] = 100;
    dims[2] = 100;
    dims[3] = 10;
    dims[4] = 10;

    itemsize = 1; // Reset and recompute if needed
    not_cf_contig = 1;
}