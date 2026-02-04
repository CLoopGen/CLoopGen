#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char png_byte;
typedef png_byte *png_bytep;
typedef unsigned int png_uint_32;

png_bytep sp;
png_bytep dp;
png_uint_32 i;
png_uint_32 row_width;
unsigned int gray;

static png_byte *sp_buffer;
static png_byte *dp_buffer;
static size_t total_data_size = 1 << 20; // 1MB data size for ~0.01 sec runtime

void init_vars() {
    sp_buffer = (png_byte*)calloc(total_data_size, sizeof(png_byte));
    dp_buffer = (png_byte*)calloc(total_data_size * 3, sizeof(png_byte)); // dp decrements more per iteration

    if (!sp_buffer || !dp_buffer) {
        exit(1);
    }

    for (size_t j = 0; j < total_data_size; j++) {
        sp_buffer[j] = (png_byte)((j * 71) % 256); // arbitrary initialization
    }

    // Initialize dp to point near the end of dp_buffer since it will be decremented
    sp = sp_buffer + total_data_size - 1;
    dp = dp_buffer + total_data_size * 3 - 1;

    row_width = total_data_size;
    gray = 128; // arbitrary choice
    i = 0;
}