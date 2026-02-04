#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef unsigned int png_uint_32;
typedef unsigned char png_byte;
typedef png_byte *png_bytep;

png_uint_32 length;
png_bytep buffer;
png_uint_32 prefix_length;

void init_vars() {
    // Target approximately 0.01 seconds runtime
    // Heuristic: assume ~1-2 GB/s scan rate for byte comparison on modern CPU
    // Use 16 MB as base size to ensure loop runs long enough
    const png_uint_32 data_size = 16 << 20; // 16 MB

    buffer = (png_bytep)aligned_alloc(32, data_size);
    if (!buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Fill with non-zero bytes initially
    memset(buffer, 1, data_size);

    // Place a zero near the end to terminate the loop
    // Ensure prefix_length stops before or at data_size
    png_uint_32 zero_pos = data_size - 1;
    buffer[zero_pos] = 0;

    length = data_size;
    prefix_length = 0; // Start from beginning
}