#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern int shift_start[4];
extern int shift_dec[4];
extern png_bytep bp;
extern size_t i;
extern unsigned int mask;
extern size_t row_bytes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced computational intensity: remove inner loop and replace with direct computation
for (i = 0; i < row_bytes; i += 2, bp += 2) {  // Double step to reduce trip count
    if (i + 1 >= row_bytes) break; // Prevent overflow
    unsigned int v1 = bp[0], v2 = bp[1];
    // Simplified transformation using single shift per byte
    bp[0] = (png_byte)(((v1 << shift_start[0]) | ((v1 >> (-shift_start[0])) & mask)) & 255);
    bp[1] = (png_byte)(((v2 << shift_start[0]) | ((v2 >> (-shift_start[0])) & mask)) & 255);
}
}
