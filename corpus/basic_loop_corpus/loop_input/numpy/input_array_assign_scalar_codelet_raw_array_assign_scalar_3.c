#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

int ndim = 4;
npy_intp shape_it[64] = {100, 50, 40, 13};
npy_intp nitems = 1;
npy_intp i;

void init_vars() {
    ndim = 4;
    shape_it[0] = 100;
    shape_it[1] = 50;
    shape_it[2] = 40;
    shape_it[3] = 13;
    for (int j = 4; j < 64; j++) {
        shape_it[j] = 1;
    }
    nitems = 1;
    i = 0;
}