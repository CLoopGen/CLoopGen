#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned int png_uint_32;
typedef unsigned char png_byte;
typedef png_byte *png_bytep;

png_uint_32 row_width;
png_bytep sp;
png_bytep dp;
png_uint_32 i;

static png_byte *sp_buffer;
static png_byte *dp_buffer;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01 sec runtime

    sp_buffer = (png_byte*)aligned_alloc(32, data_size);
    dp_buffer = (png_byte*)aligned_alloc(32, data_size);

    if (!sp_buffer || !dp_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        sp_buffer[idx] = rand() % 256;
        dp_buffer[idx] = 0;
    }

    row_width = data_size / 4; // ensure we don't overflow with step adjustments

    sp = sp_buffer + data_size - 1;
    dp = dp_buffer + data_size - 1;
}