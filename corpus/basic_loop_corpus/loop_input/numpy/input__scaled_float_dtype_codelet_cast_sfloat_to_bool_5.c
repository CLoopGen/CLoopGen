#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;
typedef unsigned char npy_bool;

npy_intp strides[2];
npy_intp N;
char *in;
char *out;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU
    N = data_size / sizeof(double);

    double *input_data = (double *)aligned_alloc(64, data_size);
    npy_bool *output_data = (npy_bool *)aligned_alloc(64, N * sizeof(npy_bool));

    if (!input_data || !output_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (npy_intp i = 0; i < N; i++) {
        input_data[i] = (i % 3) ? 1.5 : 0.0;
    }

    in = (char *)input_data;
    out = (char *)output_data;
    strides[0] = sizeof(double);
    strides[1] = sizeof(npy_bool);
}