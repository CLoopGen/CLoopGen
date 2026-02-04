#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *out;
int16_t *in;
int n_blocks;
int size;
int block_size;
int i;

void init_vars() {
    size = 64 * 1024 * 1024; // ~128MB of int16_t data (64M elements)
    block_size = 16;
    n_blocks = 8;

    in = (int16_t*)aligned_alloc(32, size * sizeof(int16_t));
    out = (int16_t*)aligned_alloc(32, size * sizeof(int16_t));

    if (!in || !out) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < size; j++) {
        in[j] = rand() % (n_blocks * block_size);
    }
}