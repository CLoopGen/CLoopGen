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
static size_t total_size;

void init_vars() {
    total_size = 64 * 1024 * 1024; // ~64 MB for ~0.01 sec runtime on modern CPU

    sp_buffer = (png_byte*)aligned_alloc(32, total_size);
    dp_buffer = (png_byte*)aligned_alloc(32, total_size);

    if (!sp_buffer || !dp_buffer) {
        exit(1);
    }

    for (size_t j = 0; j < total_size; j++) {
        sp_buffer[j] = rand() % 256;
        dp_buffer[j] = 0;
    }

    sp = sp_buffer + total_size - 4;
    dp = dp_buffer + total_size - 4;
    row_width = (total_size / 4) - 1; // ensures we don't underflow in loop
}