#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *out;
ptrdiff_t pitch;
int blk_size;
int x;
int y;
int16_t dc_coeff;

static int16_t *out_buffer;

void init_vars() {
    blk_size = 4096; 
    dc_coeff = 1234;
    pitch = blk_size;

    size_t total_size = (size_t)blk_size * blk_size * sizeof(int16_t);
    out_buffer = aligned_alloc(32, total_size);
    if (!out_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    out = out_buffer;
}

__attribute__((destructor))
static void cleanup() {
    free(out_buffer);
}