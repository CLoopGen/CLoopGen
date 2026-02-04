#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;
typedef signed char npy_int8;

int ndim;
npy_intp i;
npy_int8 *perm;

void init_vars() {
    ndim = 100000000;  // 100 million iterations ~ ~0.01 sec on modern CPU
    perm = (npy_int8*)aligned_alloc(_Alignof(npy_int8), ndim * sizeof(npy_int8));
    if (!perm) {
        exit(1);
    }
}