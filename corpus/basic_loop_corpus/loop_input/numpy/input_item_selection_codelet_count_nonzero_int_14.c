#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

int ndim;
char *data;
int idim;
npy_intp shape[64];
npy_intp strides[64];
npy_intp coord[64];

void init_vars() {
    // Set dimensions
    ndim = 3;
    
    // Define shape: 512 x 512 x 256 bytes per element (simulated as char)
    shape[0] = 1;
    shape[1] = 512;
    shape[2] = 512;
    
    // Define strides for C-order contiguous layout
    strides[2] = 1;
    strides[1] = shape[2] * strides[2];
    strides[0] = shape[1] * strides[1];
    
    // Allocate approximately 128MB: 1 * 512 * 512 = 262144 elements, each 1 byte -> ~256KB
    // To get ~128MB, we adjust last dimension size accordingly.
    // Let's instead target: 512 x 512 x 512 = 128MiB (134,217,728 bytes)
    shape[0] = 512;
    shape[1] = 512;
    shape[2] = 512;
    strides[2] = 1;
    strides[1] = shape[2] * strides[2];
    strides[0] = shape[1] * strides[1];
    
    // Total data size: 512^3 = 134,217,728 bytes (~128MB), which should run loop long enough
    data = (char *)malloc(strides[0] * shape[0]);
    if (!data) {
        exit(1);
    }
    
    // Initialize coordinate array to zero
    memset(coord, 0, sizeof(coord));
    
    // Initialize other state
    idim = 0;
}