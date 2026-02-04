#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char npy_uint8;
typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

npy_uint8 off = 42;
npy_intp cnt = 67108864;  // 64 million elements for ~64MB, targeting ~0.01 sec on modern CPU
npy_uint8 *out = NULL;
npy_intp i = 0;

void init_vars() {
    out = (npy_uint8 *)malloc(cnt * sizeof(npy_uint8));
    if (!out) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}