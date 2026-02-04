#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

npy_intp strides[2];
npy_intp N;
char *in;
char *out;

static char *in_buffer;
static char *out_buffer;
static npy_intp buffer_size;

void init_vars() {
    // Aim for approximately 64MB of data to target ~0.01 sec runtime on modern CPUs
    buffer_size = 64 * 1024 * 1024; // bytes
    
    // Allocate input and output buffers
    in_buffer = (char *)aligned_alloc(64, buffer_size);
    out_buffer = (char *)aligned_alloc(64, buffer_size);
    
    if (!in_buffer || !out_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    // Initialize input data
    for (npy_intp i = 0; i < buffer_size; i++) {
        in_buffer[i] = (char)(i & 0xFF);
    }
    
    // Set the main pointers
    in = in_buffer;
    out = out_buffer;
    
    // Set strides: advance by 8 bytes each iteration (double-sized)
    strides[0] = 8;
    strides[1] = 8;
    
    // Number of iterations: total bytes / bytes per access
    N = buffer_size / 8;
}