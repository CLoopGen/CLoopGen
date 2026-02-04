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

static char *buffer;

void init_vars() {
    npy_uintp data_size = 128 << 20; // 128 MB
    buffer = (char *)aligned_alloc(64, data_size);
    if (!buffer) {
        exit(1);
    }

    data = buffer;
    bstride = 1;
    len = data_size;
}

__attribute__((destructor))
static void cleanup() {
    free(buffer);
}