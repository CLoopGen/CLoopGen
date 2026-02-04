#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef unsigned int png_uint_32;
typedef unsigned char png_byte;
typedef png_byte *png_bytep;

png_uint_32 i;
png_uint_32 row_width;
png_byte lo_filler;
png_bytep sp;
png_bytep dp;

static png_byte *sp_buffer;
static png_byte *dp_buffer;
static size_t total_data_size = 128 * 1024 * 1024; // 128 MB

void init_vars() {
    row_width = total_data_size / sizeof(png_byte);
    
    sp_buffer = (png_byte*)calloc(row_width + 1, sizeof(png_byte));
    dp_buffer = (png_byte*)calloc(row_width * 2 + 1, sizeof(png_byte)); 
    
    if (!sp_buffer || !dp_buffer) {
        free(sp_buffer);
        free(dp_buffer);
        exit(1);
    }
    
    for (size_t idx = 0; idx < row_width; ++idx) {
        sp_buffer[idx] = (png_byte)(idx & 0xFF);
    }
    
    lo_filler = 0xAB;
    
    sp = sp_buffer + row_width;
    dp = dp_buffer + (row_width * 2);
}

__attribute__((destructor))
static void cleanup() {
    free(sp_buffer);
    free(dp_buffer);
}