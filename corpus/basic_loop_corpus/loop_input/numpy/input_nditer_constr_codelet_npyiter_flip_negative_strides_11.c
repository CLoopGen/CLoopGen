#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

npy_intp istrides = 0;
npy_intp nstrides = 1 << 20;  // Approximately 1M iterations for ~0.01 sec runtime
npy_intp *baseoffsets;
char **resetdataptr;

void init_vars() {
    baseoffsets = (npy_intp*)calloc(nstrides, sizeof(npy_intp));
    resetdataptr = (char**)calloc(nstrides, sizeof(char*));

    for (npy_intp i = 0; i < nstrides; ++i) {
        baseoffsets[i] = (i + 1) * 8;  // Non-zero offsets to ensure effect
        resetdataptr[i] = (char*)malloc(4096);  // Each pointer points to a page-sized buffer
    }
}