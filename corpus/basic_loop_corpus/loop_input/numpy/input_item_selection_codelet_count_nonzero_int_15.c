#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

int ndim;
char *data;
int idim;
npy_intp shape[64];
npy_intp strides[64];
npy_intp coord[64];

void init_vars() {
    // Set up a 2D array of doubles: 1000x1000 elements
    ndim = 2;
    
    // Each element is 8 bytes (double)
    const npy_intp itemsize = 8;
    
    // Allocate 8MB of data
    data = (char *)malloc(1000 * 1000 * itemsize);
    if (!data) exit(1);
    
    // Initialize shape: 1000 x 1000
    shape[0] = 1000;
    shape[1] = 1000;
    
    // Row-major strides: inner dimension stride is itemsize, outer is size of row
    strides[0] = 1000 * itemsize;
    strides[1] = itemsize;
    
    // Initialize coordinates to zero
    for (int i = 0; i < ndim; ++i) {
        coord[i] = 0;
    }
    
    // Ensure initial data pointer is at start
    // The loop modifies data based on coord and strides
}