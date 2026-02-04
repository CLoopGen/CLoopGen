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

static char *data_buffer;

void init_vars() {
    const size_t total_size = 128 * 1024 * 1024; // 128 MB for ~0.01 sec on modern CPU
    data_buffer = (char *)aligned_alloc(64, total_size);
    if (!data_buffer) {
        exit(1);
    }

    data = data_buffer;
    bstride = 1;
    len = total_size;
}

__attribute__((destructor)) void cleanup() {
    free(data_buffer);
}