#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern int shift;
extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;
extern png_uint_32 row_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with fixed stride on sp, dp updated every 8th step
    // Simulate reading bits in groups of 8 with sp only changing every 8 iterations
    png_uint_32 full_bytes = row_width / 8;
    png_uint_32 remainder = row_width % 8;
    png_bytep local_sp = sp;
    png_bytep local_dp = dp;

    // Process full bytes with strided access: each byte in sp is used 8 times
    for (i = 0; i < full_bytes; i++) {
        png_byte val = *local_sp;
        for (int bit = 0; bit < 8; bit++) {
            if ((val >> bit) & 1)
                *local_dp = 255;
            else
                *local_dp = 0;
            local_dp--;
        }
        local_sp--; // Move to next source byte after 8 output pixels
    }

    // Handle remaining bits
    if (remainder > 0) {
        png_byte val = *local_sp;
        for (int bit = 0; bit < remainder; bit++) {
            if ((val >> bit) & 1)
                *local_dp = 255;
            else
                *local_dp = 0;
            local_dp--;
        }
        // Update globals: shift becomes remainder, sp and dp adjusted
        shift = remainder;
        sp = local_sp;
        dp = local_dp;
    } else {
        shift = 0;
        sp = local_sp;
        dp = local_dp;
    }
}
