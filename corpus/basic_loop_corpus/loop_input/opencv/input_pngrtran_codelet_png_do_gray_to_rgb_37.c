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

static png_byte *sp_buffer;
static png_byte *dp_buffer;
static size_t total_data_size = 1 << 20; // 1MB for ~0.01 sec runtime estimate

void init_vars() {
    sp_buffer = (png_byte*)calloc(total_data_size, sizeof(png_byte));
    dp_buffer = (png_byte*)calloc(total_data_size + 12, sizeof(png_byte)); // extra padding for safety

    if (!sp_buffer || !dp_buffer) {
        exit(1);
    }

    for (size_t idx = 0; idx < total_data_size; ++idx) {
        sp_buffer[idx] = (png_byte)(idx % 256);
    }

    row_width = total_data_size / 6; // each loop iteration accesses up to 6 elements from sp
    sp = sp_buffer + total_data_size - 1;
    dp = dp_buffer + total_data_size + 11; // ensure enough room to write backwards
}