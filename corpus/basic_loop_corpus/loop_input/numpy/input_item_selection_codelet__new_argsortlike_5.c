#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

npy_intp N = 1000000;
npy_intp rstride = sizeof(npy_intp);
npy_intp *iptr;
npy_intp i;
char *rptr;

void init_vars() {
    // Allocate input array iptr with N elements
    iptr = (npy_intp*)malloc(N * sizeof(npy_intp));
    if (!iptr) {
        fprintf(stderr, "Failed to allocate iptr\n");
        exit(1);
    }

    // Allocate output buffer rptr with enough space: at least (N-1)*rstride + sizeof(npy_intp)
    size_t rptr_size = (N - 1) * rstride + sizeof(npy_intp);
    rptr = (char*)malloc(rptr_size);
    if (!rptr) {
        fprintf(stderr, "Failed to allocate rptr\n");
        free(iptr);
        exit(1);
    }

    // Initialize iptr with sample data
    for (npy_intp idx = 0; idx < N; ++idx) {
        iptr[idx] = idx * 2 + 1;
    }

    // Reset loop index
    i = 0;
}