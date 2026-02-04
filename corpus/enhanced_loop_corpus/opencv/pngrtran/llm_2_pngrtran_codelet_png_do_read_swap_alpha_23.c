#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int png_uint_32;

typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern png_uint_32 row_width;
extern png_bytep sp;
extern png_bytep dp;
extern png_byte save[2];
extern png_uint_32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access with forward indexing (reversed logic using pointer arithmetic from base)
    png_bytep sp_end = sp - row_width * 4;
    png_bytep dp_end = dp - row_width * 4;
    for (i = 0; i < row_width; i++) {
        // Access elements consecutively in reverse order without repeated pre-decrement
        png_byte s1 = *(sp_end + i*4 + 3);
        png_byte s2 = *(sp_end + i*4 + 2);
        png_byte s3 = *(sp_end + i*4 + 1);
        png_byte s4 = *(sp_end + i*4 + 0);

        // Write to destination in reverse segment order
        *(dp_end + i*4 + 3) = s1;
        *(dp_end + i*4 + 2) = s2;
        *(dp_end + i*4 + 1) = s4;  // swapped
        *(dp_end + i*4 + 0) = s3;  // swapped

        // Simulate original save behavior with local storage
        save[0] = s1;
        save[1] = s2;
    }
}
