#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;
typedef signed char npy_int8;

int idim;
npy_intp new_ndim;
npy_int8 *perm;

void init_vars() {
    new_ndim = 134217728; // ~128MB of data (134M elements * 1 byte)
    perm = (npy_int8 *)aligned_alloc(64, new_ndim * sizeof(npy_int8));
    if (!perm) {
        exit(1);
    }
}