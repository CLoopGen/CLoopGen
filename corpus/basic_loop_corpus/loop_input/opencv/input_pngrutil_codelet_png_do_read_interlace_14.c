#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned int png_uint_32;
typedef unsigned char png_byte;

typedef struct png_row_info_struct {
    png_uint_32 width;
    size_t rowbytes;
    png_byte color_type;
    png_byte bit_depth;
    png_byte channels;
    png_byte pixel_depth;
} png_row_info;

typedef png_row_info *png_row_infop;
typedef png_byte *png_bytep;

static png_row_info row_info_instance;
static png_byte *sp_buffer;
static png_byte *dp_buffer;

png_row_infop row_info = &row_info_instance;
png_bytep sp = NULL;
png_bytep dp = NULL;
unsigned int sshift;
unsigned int dshift;
unsigned int s_start;
unsigned int s_end;
int s_inc;
int jstop;
png_uint_32 i;

void init_vars() {
    // Initialize parameters to ensure the loop runs for ~0.01 seconds
    // Assume modern CPU can do ~1e8 operations per second, so aim for ~1e6 iterations

    row_info->width = 100000;  // 100k iterations of outer loop
    jstop = 6;                 // Inner loop 6 times -> 600k total memory updates

    // Set up shift parameters: simulate 2-bit pixel packing
    s_start = 6;
    s_end = 0;
    s_inc = -2;
    sshift = s_start;

    dshift = s_start;
    // dp will write into bytes, shifting bits within each byte

    // Allocate buffers with margin to avoid underflow during pointer decrements
    // Maximum dp decrement: jstop * (number of outer loops where dshift == s_end)
    // At most every 4 steps (since pixel is 2-bit, 4 pixels per byte) -> about width/4 times
    // So dp decrements at most jstop * (width / 4) / 8? But logic is per-byte.
    // Actually, each time dshift reaches end, we move to next (previous) byte
    // Since we pack 4 pixels per byte (2 bits each), we'll cross a byte boundary every 4 pixels
    // So number of dp-- operations ~ (width + 3)/4, but jstop adds multiple writes per output

    // Be safe: allocate extra space in both directions
    size_t buffer_size = (row_info->width * 3 / 4) + 16;  // generous estimate for packed data
    sp_buffer = (png_bytep)calloc(buffer_size, sizeof(png_byte));
    dp_buffer = (png_bytep)calloc(buffer_size, sizeof(png_byte));

    if (!sp_buffer || !dp_buffer) {
        exit(1);
    }

    // Initialize sp to point near middle so it can decrement safely
    sp = sp_buffer + (buffer_size - 10);
    dp = dp_buffer + (buffer_size - 10);

    // Fill sp_buffer with some sample data
    for (size_t idx = 0; idx < buffer_size; idx++) {
        sp_buffer[idx] = (png_byte)(0xAA ^ (idx & 0xFF)); // alternating pattern
    }
}