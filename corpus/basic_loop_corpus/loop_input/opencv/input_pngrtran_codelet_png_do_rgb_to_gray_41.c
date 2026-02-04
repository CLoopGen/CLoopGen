#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned int png_uint_32;
typedef unsigned char png_byte;
typedef png_byte *png_bytep;

int rgb_error = 0;
png_uint_32 rc = 8192;
png_uint_32 gc = 8192;
png_uint_32 bc = 8192;
png_uint_32 row_width = 1048576; // ~1M pixels, scales to ~3-4MB input
int have_alpha = 1;

png_bytep sp = NULL;
png_bytep dp = NULL;
png_uint_32 i = 0;

void init_vars() {
    const size_t total_input_size = row_width * (have_alpha ? 4 : 3);
    const size_t total_output_size = row_width * (have_alpha ? 2 : 1);

    sp = malloc(total_input_size);
    dp = malloc(total_output_size);

    if (!sp || !dp) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    for (png_uint_32 idx = 0; idx < row_width; idx++) {
        size_t base_in = idx * (have_alpha ? 4 : 3);
        sp[base_in + 0] = (png_byte)(idx % 256);       // red
        sp[base_in + 1] = (png_byte)((idx * 3) % 256); // green
        sp[base_in + 2] = (png_byte)((idx * 5) % 256); // blue
        if (have_alpha) {
            sp[base_in + 3] = (png_byte)((idx * 7) % 256); // alpha
        }
    }

    for (png_uint_32 idx = 0; idx < total_output_size; idx++) {
        dp[idx] = 0;
    }

    i = 0;
    rgb_error = 0;
}