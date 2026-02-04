#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

int iop;
int nop = 1000000;
npy_intp delta = 8;
npy_intp *strides;
char **ptrs;

void init_vars() {
    strides = (npy_intp *)aligned_alloc(64, nop * sizeof(npy_intp));
    ptrs = (char **)aligned_alloc(64, nop * sizeof(char *));
    
    for (int i = 0; i < nop; ++i) {
        strides[i] = (i % 16) + 1;
        ptrs[i] = (char *)aligned_alloc(64, 256);
    }
}