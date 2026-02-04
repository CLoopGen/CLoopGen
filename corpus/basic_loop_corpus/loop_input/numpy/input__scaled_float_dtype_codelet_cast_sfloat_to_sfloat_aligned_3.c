#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

npy_intp strides[2];
double factor;
npy_intp N;
char *in;
char *out;

static char *in_buffer;
static char *out_buffer;

void init_vars() {
    factor = 2.5;
    N = 10000000;  // Adjust to achieve ~0.01 sec runtime

    strides[0] = sizeof(double);
    strides[1] = sizeof(double);

    in_buffer = (char *)aligned_alloc(64, N * sizeof(double));
    out_buffer = (char *)aligned_alloc(64, N * sizeof(double));

    if (!in_buffer || !out_buffer) {
        exit(1);
    }

    in = in_buffer;
    out = out_buffer;

    for (npy_intp i = 0; i < N; i++) {
        ((double *)in_buffer)[i] = (double)(i % 1000) + 0.5;
    }
}