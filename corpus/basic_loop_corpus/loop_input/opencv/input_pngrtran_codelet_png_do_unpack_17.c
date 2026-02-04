#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned int png_uint_32;
typedef unsigned char png_byte;
typedef png_byte *png_bytep;

png_uint_32 i;
png_uint_32 row_width;
png_bytep sp;
png_bytep dp;
png_uint_32 shift;

static png_byte *sp_buffer;
static png_byte *dp_buffer;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate

    sp_buffer = (png_byte*)aligned_alloc(32, data_size);
    dp_buffer = (png_byte*)aligned_alloc(32, data_size);

    if (!sp_buffer || !dp_buffer) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        sp_buffer[idx] = rand() & 0xFF;
        dp_buffer[idx] = 0;
    }

    row_width = data_size - 1;
    shift = 6;

    sp = sp_buffer + data_size - 1;
    dp = dp_buffer + data_size - 1;
}