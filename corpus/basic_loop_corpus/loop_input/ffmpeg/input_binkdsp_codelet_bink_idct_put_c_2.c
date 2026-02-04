#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *dest;
int linesize;
int i;
int temp[64];

void init_vars() {
    linesize = 8;
    size_t dest_size = 256 * 1024 * 1024; // 256 MB to ensure ~0.01s runtime
    dest = (uint8_t*)aligned_alloc(32, dest_size);
    if (!dest) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < 64; idx++) {
        temp[idx] = (idx * 17) % 512 - 256; // Populate with deterministic non-zero values
    }

    for (size_t idx = 0; idx < dest_size; idx++) {
        dest[idx] = 0;
    }
}