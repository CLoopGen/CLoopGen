#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

void *p;
npy_intp stride;
npy_intp n;
char *a;

static char *buffer = NULL;

void init_vars() {
    // Allocate 64MB of data to ensure loop runs for measurable time (~0.01 sec on modern CPU)
    npy_intp buffer_size = 64 * 1024 * 1024;
    buffer = (char *)aligned_alloc(64, buffer_size);
    if (!buffer) {
        exit(1);
    }

    p = buffer;
    stride = 1;  // Simple byte stride
    n = buffer_size;  // Number of iterations to cover entire buffer
    a = NULL;  // Will be initialized in loop
}