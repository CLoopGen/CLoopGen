#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *b;
size_t blen;
size_t i;
uint64_t r;

static unsigned char *internal_b;

void init_vars() {
    size_t data_size = 512 * 1024; // 512 KB for ~0.01 sec runtime on modern CPU
    internal_b = malloc(data_size);
    if (!internal_b) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize buffer with predictable non-zero pattern
    for (size_t idx = 0; idx < data_size; ++idx) {
        internal_b[idx] = (unsigned char)(idx & 0xFF);
    }

    // Initialize external symbols
    b = internal_b;
    blen = data_size;
    i = 0;
    r = 0;
}