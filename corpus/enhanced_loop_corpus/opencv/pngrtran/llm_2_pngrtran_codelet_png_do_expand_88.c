#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_byte green_high;
extern png_byte blue_high;
extern png_byte red_low;
extern png_byte green_low;
extern png_byte blue_low;
extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;
extern png_uint_32 row_width;
extern png_byte red_high;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with local accumulation
    png_byte buffer[6];
    for (i = 0; i < row_width; i++) {
        // Load 6 consecutive bytes into a local buffer for coherent access
        buffer[0] = *(sp - 5);
        buffer[1] = *(sp - 4);
        buffer[2] = *(sp - 3);
        buffer[3] = *(sp - 2);
        buffer[4] = *(sp - 1);
        buffer[5] = *(sp);

        if (buffer[0] == red_high && buffer[1] == red_low && 
            buffer[2] == green_high && buffer[3] == green_low && 
            buffer[4] == blue_high && buffer[5] == blue_low) {
            *dp-- = 0;
            *dp-- = 0;
        } else {
            *dp-- = 255;
            *dp-- = 255;
        }

        // Store in reverse order but from buffered values for predictable access
        *dp-- = buffer[5];
        *dp-- = buffer[4];
        *dp-- = buffer[3];
        *dp-- = buffer[2];
        *dp-- = buffer[1];
        *dp-- = buffer[0];

        sp -= 6; // Adjust source pointer after processing six elements
    }
}
