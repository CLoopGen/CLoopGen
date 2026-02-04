#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ssize_t besti;
ssize_t i;
unsigned char *o;
unsigned char unordered[16];

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU

    o = (unsigned char *)malloc(data_size);
    if (!o) {
        exit(1);
    }

    besti = data_size;

    for (ssize_t idx = 0; idx < (ssize_t)data_size; idx++) {
        o[idx] = (unsigned char)(idx % 16); // ensure o[i] is always in [0,15]
    }

    for (int j = 0; j < 16; j++) {
        unordered[j] = 1; // initialize to non-zero
    }
}