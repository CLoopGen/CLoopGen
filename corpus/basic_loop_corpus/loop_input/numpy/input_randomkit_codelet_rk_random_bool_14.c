#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char npy_bool;
typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

npy_bool off = 1;
npy_intp cnt = 32 * 1024 * 1024; // 32 million elements, ~32 MB for npy_bool
npy_bool *out = NULL;
npy_intp i = 0;

void init_vars() {
    out = (npy_bool*)calloc(cnt, sizeof(npy_bool));
    if (!out) {
        fprintf(stderr, "Failed to allocate memory for out\n");
        exit(1);
    }
}