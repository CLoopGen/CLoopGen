#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

npy_intp i;
npy_intp temp;
npy_intp size;
npy_intp *first;
npy_intp *last;

void init_vars() {
    size = 16777216;  // 16M elements, ~128MB total for two arrays (assuming npy_intp is 8 bytes)

    first = (npy_intp*)aligned_alloc(64, size * sizeof(npy_intp));
    last = (npy_intp*)aligned_alloc(64, size * sizeof(npy_intp));

    if (!first || !last) {
        exit(1);
    }

    for (npy_intp idx = 0; idx < size; ++idx) {
        first[idx] = idx;
        last[idx] = size - idx;
    }
}