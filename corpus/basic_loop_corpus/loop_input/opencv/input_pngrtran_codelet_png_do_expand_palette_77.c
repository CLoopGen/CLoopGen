#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char png_byte;
typedef png_byte *png_bytep;
typedef unsigned int png_uint_32;

int shift;
png_bytep sp;
png_bytep dp;
png_uint_32 i;
png_uint_32 row_width;

static png_byte *sp_buffer;
static png_byte *dp_buffer;

void init_vars() {
    const size_t data_size = 128 * 1024 * 1024; // 128 MB for ~0.01 sec runtime estimate

    sp_buffer = (png_byte*)aligned_alloc(64, data_size);
    dp_buffer = (png_byte*)aligned_alloc(64, data_size);

    if (!sp_buffer || !dp_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        sp_buffer[idx] = rand() & 0xFF;
        dp_buffer[idx] = 0;
    }

    sp = sp_buffer + data_size - 1;
    dp = dp_buffer + data_size - 1;
    shift = 0;
    row_width = data_size;
}