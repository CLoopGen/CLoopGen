#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern int shift;
extern int value;
extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;
extern png_uint_32 row_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with forward pointer traversal
    // Instead of decrementing dp and conditionally decrementing sp, we process in increasing address order
    // We assume sp and dp are adjusted externally to point to the start of their respective buffers
    // Here, we simulate a reversed input by pre-adjusting logic and using incrementing indices

    png_bytep temp_sp = sp - (row_width - 1);  // Point to the beginning of the data segment
    png_bytep temp_dp = dp - (row_width - 1);
    int local_shift = shift;

    for (i = 0; i < row_width; i++) {
        value = (temp_sp[i] >> local_shift) & 3;
        temp_dp[i] = (png_byte)(value | (value << 2) | (value << 4) | (value << 6));
        if (local_shift == 6) {
            local_shift = 0;
        } else {
            local_shift += 2;
        }
    }
}
