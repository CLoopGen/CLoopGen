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

static char *data_buffer;

void init_vars() {
    npy_intp data_size = 64 * 1024 * 1024; // ~64 MB for ~0.01 sec on typical CPU
    stride = sizeof(char);
    n = data_size;
    data_buffer = (char *)aligned_alloc(64, data_size);
    if (!data_buffer) {
        exit(1);
    }
    p = data_buffer;
    a = NULL;
}