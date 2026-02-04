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

void init_vars() {
    // Set data size to achieve around 0.01 seconds runtime
    // Each loop iteration processes several bytes and decrements pointers
    // Aim for approximately 16 million iterations to hit target runtime
    row_width = 16000000;

    // Allocate buffers with extra space to prevent out-of-bounds access
    // Each iteration accesses up to sp-1, so we need at least 2 extra bytes at beginning
    // And we write multiple bytes to dp, so need sufficient space
    size_t sp_size = row_width * 8 + 16;
    size_t dp_size = row_width * 8 + 16;

    sp_buffer = (png_byte*)calloc(sp_size, sizeof(png_byte));
    dp_buffer = (png_byte*)calloc(dp_size, sizeof(png_byte));

    if (!sp_buffer || !dp_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize sp to point near the end of buffer (so sp-- is safe)
    // Leave room for initial sp-1 access
    sp = sp_buffer + 8 + row_width * 8 - 1;
    
    // Initialize dp to point near the end of destination buffer
    dp = dp_buffer + 8 + row_width * 8 - 1;

    // Initialize source data
    for (size_t idx = 0; idx < sp_size; idx++) {
        sp_buffer[idx] = (png_byte)(idx * 7919 % 251); // Prime-based pattern
    }
}

// Cleanup function to free allocated memory (not required by problem but good practice)
void cleanup_vars() {
    free(sp_buffer);
    free(dp_buffer);
    sp_buffer = NULL;
    dp_buffer = NULL;
}