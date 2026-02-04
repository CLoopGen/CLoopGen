#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

typedef ptrdiff_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

npy_intp istrides;
npy_intp nstrides;

void init_vars() {
    nstrides = 10000000; // Adjusted to achieve ~0.01 seconds runtime on typical modern CPU
}