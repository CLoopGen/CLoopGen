#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

int newnd = 1000000;
npy_intp *newstrides;
npy_intp last_stride = 8;
int ni = 500000;
int nk;

void init_vars() {
    newstrides = (npy_intp *)calloc(newnd, sizeof(npy_intp));
    if (!newstrides) {
        exit(1);
    }
}