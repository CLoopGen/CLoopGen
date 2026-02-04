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

static int16_t *out_buffer = NULL;

void init_vars() {
    blk_size = 2048;
    dc_coeff = 42;
    pitch = blk_size;

    size_t buffer_size = (size_t)blk_size * blk_size * sizeof(int16_t);
    out_buffer = (int16_t *)calloc(1, buffer_size);
    if (!out_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    out = out_buffer;
}