#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int INTFLOAT;

INTFLOAT *buf;
int i;

static INTFLOAT *internal_buf;
static size_t data_size;

void init_vars() {
    data_size = 64 * 1024 * 1024; // ~64MB of data for sufficient runtime (~0.01 sec on modern CPU)
    internal_buf = (INTFLOAT*)aligned_alloc(32, data_size * sizeof(INTFLOAT));
    if (!internal_buf) {
        exit(1);
    }
    buf = internal_buf;

    // Initialize buffer with non-zero values to ensure meaningful computation
    for (size_t j = 0; j < data_size; j++) {
        internal_buf[j] = (INTFLOAT)(j % 32);
    }

    i = 0;
}