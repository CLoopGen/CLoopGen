#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef size_t npy_uintp;

char *c;
npy_uintp i;
npy_uintp count;

void init_vars() {
    const npy_uintp data_size = 128 * 1024 * 1024; // 128 MB
    c = (char *)aligned_alloc(64, data_size);
    if (!c) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (npy_uintp idx = 0; idx < data_size; ++idx) {
        c[idx] = (char)(idx % 256);
    }
    i = 0;
    count = 0;
}