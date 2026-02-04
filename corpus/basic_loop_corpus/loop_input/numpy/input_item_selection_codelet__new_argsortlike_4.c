#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

npy_intp N;
npy_intp *iptr;
npy_intp i;

npy_intp *original_iptr_storage = NULL;

void init_vars() {
    N = 64 * 1024 * 1024 / sizeof(npy_intp);  // ~64M elements to target ~0.01 sec runtime
    original_iptr_storage = (npy_intp *)calloc(N, sizeof(npy_intp));
    if (!original_iptr_storage) {
        exit(1);
    }
    iptr = original_iptr_storage;
}