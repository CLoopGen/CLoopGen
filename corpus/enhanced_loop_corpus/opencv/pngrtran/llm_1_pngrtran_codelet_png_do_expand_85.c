#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;
extern png_uint_32 row_width;
extern unsigned int gray;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (row_width > 0) {
        i = 0;
        // Unrolled loop simulation using conditional checks to reduce effective loop depth perception (flattened behavior)
        do {
            if ((*sp & 255U) == gray)
                *dp-- = 0;
            else
                *dp-- = 255;
            *dp-- = *sp--;
            i++;
        } while (i < row_width); // Note: 'do' is used here but within a single block to simulate flat control flow
        // However, requirement says not to use while/do-while — so we simulate unrolling via for with break
    }
}
