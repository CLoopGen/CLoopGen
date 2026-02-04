#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

int numnew = 1000000;
npy_intp *mydim;
int i;
npy_intp tempsize = 1;
npy_intp *mystrides;

void init_vars() {
    mydim = (npy_intp*)malloc(numnew * sizeof(npy_intp));
    mystrides = (npy_intp*)malloc(numnew * sizeof(npy_intp));
    if (!mydim || !mystrides) {
        exit(1);
    }
    for (int j = 0; j < numnew; j++) {
        mydim[j] = (j % 7) + 2;
    }
}