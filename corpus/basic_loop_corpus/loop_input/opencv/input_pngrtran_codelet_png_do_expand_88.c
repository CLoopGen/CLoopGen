#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char png_byte;
typedef png_byte *png_bytep;
typedef unsigned int png_uint_32;

png_byte green_high = 0xAA;
png_byte blue_high = 0xBB;
png_byte red_low = 0x11;
png_byte green_low = 0x22;
png_byte blue_low = 0x33;
png_byte red_high = 0xFF;

static png_bytep sp_base;
static png_bytep dp_base;
png_bytep sp;
png_bytep dp;
png_uint_32 i;
png_uint_32 row_width;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01s runtime
    sp_base = (png_bytep)aligned_alloc(32, data_size + 8);
    dp_base = (png_bytep)aligned_alloc(32, data_size * 2 + 16); // dp needs more space due to pre-decrement

    if (!sp_base || !dp_base) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size + 8; idx++) {
        sp_base[idx] = (png_byte)(idx & 0xFF);
    }

    // Ensure the pattern condition is occasionally true
    for (size_t idx = 8; idx < data_size + 8; idx += 16) {
        sp_base[idx - 5] = red_high;
        sp_base[idx - 4] = red_low;
        sp_base[idx - 3] = green_high;
        sp_base[idx - 2] = green_low;
        sp_base[idx - 1] = blue_high;
        sp_base[idx - 0] = blue_low;
    }

    // Initialize dp memory to known values
    for (size_t idx = 0; idx < data_size * 2 + 16; idx++) {
        dp_base[idx] = 0xCD;
    }

    // Set sp and dp to end of their respective data blocks to work backwards
    sp = sp_base + data_size + 7;
    dp = dp_base + (data_size * 2) + 15;

    row_width = data_size / 6; // ensures we have enough bytes for 6 * row_width in loop body
}