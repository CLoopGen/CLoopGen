#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned int png_uint_32;
typedef unsigned char png_byte;
typedef png_byte *png_bytep;

png_uint_32 i;
png_uint_32 row_width;
png_byte hi_filler;
png_byte lo_filler;
png_bytep sp;
png_bytep dp;

static png_byte *sp_buffer;
static png_byte *dp_buffer;
static size_t buffer_size;

void init_vars() {
    buffer_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU

    sp_buffer = (png_byte*)malloc(buffer_size);
    dp_buffer = (png_byte*)malloc(buffer_size);

    if (!sp_buffer || !dp_buffer) {
        free(sp_buffer);
        free(dp_buffer);
        exit(1);
    }

    for (size_t j = 0; j < buffer_size; j++) {
        sp_buffer[j] = (png_byte)(j & 0xFF);
    }

    hi_filler = 0xFF;
    lo_filler = 0x00;

    sp = sp_buffer + buffer_size;
    dp = dp_buffer + buffer_size;

    row_width = buffer_size / 4;
}