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
    // Allocate approximately 64MB of data to target ~0.01 sec runtime
    // Adjust row_width so that the loop accesses valid memory with pre-decrement
    row_width = 8 * 1024 * 1024;  // 8M iterations

    // Allocate buffers with extra space for initial pointer positions and decrements
    // Each iteration does dp-- three times -> total dp moves: 3 * row_width
    // sp is decremented once per iteration -> sp moves: row_width
    // So we need at least (3 * row_width) space in dp_buffer and (row_width) in sp_buffer
    // But since pointers start high and go low, we allocate and set sp/dp to end
    sp_buffer = (png_byte*)calloc(row_width + 1, sizeof(png_byte));
    dp_buffer = (png_byte*)calloc(3 * row_width + 3, sizeof(png_byte));

    if (!sp_buffer || !dp_buffer) {
        exit(1);
    }

    // Initialize sp to point one past the end of sp_buffer (so sp-- lands on last element first)
    sp = sp_buffer + row_width - 1;
    // Initialize dp to point to a position that allows 3*row_width decrements safely
    dp = dp_buffer + (3 * row_width) - 1;

    // Initialize input data
    for (png_uint_32 j = 0; j < row_width; j++) {
        sp_buffer[j] = (png_byte)(j & 0xFF);
    }
}

// Reset pointers if needed after multiple calls
void reset_pointers() {
    sp = sp_buffer + row_width - 1;
    dp = dp_buffer + (3 * row_width) - 1;
}