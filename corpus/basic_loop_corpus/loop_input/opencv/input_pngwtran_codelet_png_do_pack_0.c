#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char png_byte;
typedef png_byte *png_bytep;
typedef unsigned int png_uint_32;

png_bytep sp;
png_bytep dp;
int mask;
int v;
png_uint_32 i;
png_uint_32 row_width;

static png_byte *sp_buffer;
static png_byte *dp_buffer;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate

    sp_buffer = (png_byte*)calloc(data_size, sizeof(png_byte));
    dp_buffer = (png_byte*)calloc(data_size / 8, sizeof(png_byte));

    if (!sp_buffer || !dp_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        sp_buffer[idx] = rand() % 256;
    }

    sp = sp_buffer;
    dp = dp_buffer;
    mask = 128;
    v = 0;
    row_width = data_size;
}