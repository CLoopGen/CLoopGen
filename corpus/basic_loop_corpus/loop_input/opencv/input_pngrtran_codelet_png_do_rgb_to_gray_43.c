#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned int png_uint_32;
typedef unsigned char png_byte;
typedef png_byte *png_bytep;
typedef unsigned short png_uint_16;

int rgb_error;
png_uint_32 rc;
png_uint_32 gc;
png_uint_32 bc;
png_uint_32 row_width;
int have_alpha;
png_bytep sp;
png_bytep dp;
png_uint_32 i;

static png_byte *sp_data;
static png_byte *dp_data;

void init_vars() {
    // Set coefficients for RGB to grayscale conversion (typical values)
    rc = 6962;   // ~0.2126 * (1 << 15)
    gc = 23434;  // ~0.7152 * (1 << 15)
    bc = 2366;   // ~0.0722 * (1 << 15)

    // Default no error
    rgb_error = 0;

    // Assume alpha channel is present
    have_alpha = 1;

    // Define input data size: aim for ~100ms runtime
    // Each iteration consumes 6 bytes from sp, produces 4 or 6 bytes to dp
    // Estimate: 64 million pixels => ~384MB input, ~256-384MB output
    // Adjusted to run ~0.01s: use ~6-8 million pixels
    row_width = 8000000;

    // Allocate sp buffer: 6 bytes per pixel (RGB 16-bit) + 2 per alpha if needed
    size_t sp_size = row_width * (6 + (have_alpha ? 2 : 0));
    sp_data = (png_byte*)malloc(sp_size);
    if (!sp_data) {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }

    // Allocate dp buffer: 2 bytes per gray16 + 2 per alpha
    size_t dp_size = row_width * (2 + (have_alpha ? 2 : 0));
    dp_data = (png_byte*)malloc(dp_size);
    if (!dp_data) {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }

    // Initialize sp_data with test pattern: increasing 16-bit RGB values
    for (png_uint_32 idx = 0; idx < row_width; idx++) {
        int offset = idx * (6 + (have_alpha ? 2 : 0));
        // Red
        sp_data[offset + 0] = (png_byte)((idx >> 8) & 255);
        sp_data[offset + 1] = (png_byte)(idx & 255);
        // Green
        sp_data[offset + 2] = (png_byte)((idx >> 8) & 255);
        sp_data[offset + 3] = (png_byte)(idx & 255);
        // Blue
        sp_data[offset + 4] = (png_byte)((idx >> 8) & 255);
        sp_data[offset + 5] = (png_byte)(idx & 255);
        // Alpha if present
        if (have_alpha) {
            sp_data[offset + 6] = 255;
            sp_data[offset + 7] = 255;
        }
    }

    // Set pointer variables
    sp = sp_data;
    dp = dp_data;
}