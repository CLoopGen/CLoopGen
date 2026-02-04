#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
ptrdiff_t stride;
int b_h;
int y;
unsigned int color4;

void init_vars() {
    const size_t total_data_size = 16 * 1024 * 1024; // ~16 MB for sufficient runtime (~0.01 sec)
    b_h = 1024;
    stride = 64; // Ensures each row is 64 bytes apart
    color4 = 0xABCDEF00;

    dst = aligned_alloc(64, total_data_size);
    if (!dst) {
        exit(1);
    }
}

__attribute__((destructor)) void cleanup() {
    free(dst);
}