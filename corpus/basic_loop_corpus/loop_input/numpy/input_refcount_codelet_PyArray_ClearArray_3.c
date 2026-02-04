#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

int idim;
int ndim = 4;
npy_intp shape_it[64] = {1, 512, 512, 4};
npy_intp strides_it[64] = {0, 2048, 4, 1};
npy_intp coord[64] = {0};
char *data_it;

void init_vars() {
    const size_t total_size = 1024 * 1024 * 4; // ~4MB to ensure sufficient runtime (~0.01s target)
    data_it = (char *)aligned_alloc(64, total_size);
    if (!data_it) {
        exit(1);
    }
    for (size_t i = 0; i < total_size; ++i) {
        data_it[i] = (char)(i & 0xFF);
    }
    idim = 1;
    for (int i = 0; i < 64; ++i) {
        coord[i] = 0;
    }
}