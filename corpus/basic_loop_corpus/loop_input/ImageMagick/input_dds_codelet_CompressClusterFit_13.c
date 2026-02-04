#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

ssize_t bestj;
ssize_t bestk;
ssize_t i;
unsigned char *o;
unsigned char unordered[16];

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate

    o = (unsigned char *)aligned_alloc(32, data_size);
    if (!o) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        o[idx] = rand() % 16; // ensure index into unordered[0..15]
    }

    bestj = 0;
    bestk = (ssize_t)data_size;

    for (int idx = 0; idx < 16; ++idx) {
        unordered[idx] = 0;
    }
}