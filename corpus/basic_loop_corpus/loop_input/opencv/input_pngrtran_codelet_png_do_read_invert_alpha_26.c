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

static png_byte *sp_base;
static png_byte *dp_base;
static size_t total_data_size;

void init_vars() {
    // Aim for approximately 64MB of data to ensure loop runs long enough (~0.01 sec)
    // Each iteration processes 2 bytes from sp and writes 2 bytes to dp
    // So we need about 32M iterations -> set row_width = 32 * 1024 * 1024
    row_width = 32 * 1024 * 1024;
    total_data_size = row_width * 2;  // Each iteration handles 2 bytes

    // Allocate memory with extra space for pre-decrement safety
    sp_base = (png_byte*)calloc(total_data_size + 32, sizeof(png_byte));
    dp_base = (png_byte*)calloc(total_data_size + 32, sizeof(png_byte));

    if (!sp_base || !dp_base) {
        exit(1);
    }

    // Initialize source data
    for (size_t idx = 0; idx < total_data_size; idx++) {
        sp_base[idx] = (png_byte)(idx % 256);
    }

    // Set sp and dp to point past the valid data so that --sp and --dp
    // will correctly traverse backward through the data
    sp = sp_base + total_data_size;
    dp = dp_base + total_data_size;
}