#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

npy_intp *newdims;
npy_intp *newstrides;
int ni;
int nj;
int nk;

void init_vars() {
    ni = 1;
    nj = 1000000;
    nk = 0;

    newdims = (npy_intp *)aligned_alloc(64, sizeof(npy_intp) * (nj + 1));
    newstrides = (npy_intp *)aligned_alloc(64, sizeof(npy_intp) * (nj + 1));

    for (int i = 0; i < nj + 1; i++) {
        newdims[i] = 8;
        newstrides[i] = (i == 0) ? 1 : 0;
    }
}