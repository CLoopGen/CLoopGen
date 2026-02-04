#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;
typedef unsigned char npy_bool;

npy_intp *strides;
npy_intp *dims;
int nd = 4;
size_t itemsize = 1;
int i;
npy_bool not_cf_contig = 1;

void init_vars() {
    // Allocate arrays based on nd
    strides = (npy_intp*)malloc(nd * sizeof(npy_intp));
    dims = (npy_intp*)malloc(nd * sizeof(npy_intp));
    
    // Set dimensions to create a large data size (~64MB total)
    // Total elements: 256 * 256 * 256 * 4 = 67,108,864
    // With itemsize starting at 1, final buffer would be ~64MB if it were a real array
    dims[0] = 256;
    dims[1] = 256;
    dims[2] = 256;
    dims[3] = 4;
}