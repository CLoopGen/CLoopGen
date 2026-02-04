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
    const npy_uintp total_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec on typical CPU
    buffer = (char *)aligned_alloc(64, total_size);
    if (!buffer) {
        exit(1);
    }

    data = buffer;
    bstride = 1;
    len = total_size;
}

__attribute__((destructor))
static void cleanup() {
    free(buffer);
}