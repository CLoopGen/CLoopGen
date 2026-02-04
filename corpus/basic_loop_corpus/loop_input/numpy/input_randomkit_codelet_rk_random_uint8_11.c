#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char npy_uint8;
typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

npy_uint8 off = 10;
npy_uint8 rng = 200;
npy_intp cnt = 67108864; // ~64M iterations to target ~0.01 sec runtime
npy_uint8 *out;
npy_uint8 val = 150;
npy_intp i;
int bcnt = 0;

void init_vars() {
    out = (npy_uint8*)aligned_alloc(32, cnt * sizeof(npy_uint8));
    if (!out) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
}