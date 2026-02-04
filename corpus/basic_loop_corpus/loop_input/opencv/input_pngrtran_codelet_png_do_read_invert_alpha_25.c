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
static size_t total_data_size;

void init_vars() {
    total_data_size = 128 * 1024 * 1024; // 128 MB of data

    sp_buffer = (png_byte*)aligned_alloc(32, total_data_size);
    dp_buffer = (png_byte*)aligned_alloc(32, total_data_size);

    if (!sp_buffer || !dp_buffer) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    for (size_t idx = 0; idx < total_data_size; ++idx) {
        sp_buffer[idx] = rand() % 256;
        dp_buffer[idx] = 0;
    }

    sp = sp_buffer + total_data_size - 1;
    dp = dp_buffer + total_data_size - 1;
    row_width = total_data_size / 8;
}