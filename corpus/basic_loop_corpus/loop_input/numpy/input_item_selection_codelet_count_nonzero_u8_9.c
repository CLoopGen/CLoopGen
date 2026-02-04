#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;
typedef size_t npy_uintp;

char *data;
npy_intp bstride;
npy_uintp len;
npy_intp count;

static char *internal_data = NULL;

void init_vars() {
    const npy_uintp data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU
    internal_data = (char *)calloc(data_size, sizeof(char));
    if (!internal_data) {
        exit(1);
    }

    // Initialize with some non-zero pattern to make counting meaningful
    for (npy_uintp i = 0; i < data_size; ++i) {
        internal_data[i] = (char)(i % 256);
    }

    data = internal_data;
    bstride = 1;
    len = data_size;
    count = 0;
}