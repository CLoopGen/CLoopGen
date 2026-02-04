#include <stdio.h>

#include <inttypes.h>

typedef unsigned char UChar;

typedef unsigned short UInt16;

typedef int Int32;

extern UChar *block;
extern UInt16 *quadrant;
extern Int32 nblock;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to access alternating elements
    // This changes sequential access into a strided pattern, still covering the same logical range
    Int32 len = 2 + 12 + 18 + 2;
    for (i = 0; i < len; i += 2) {
        if (i + 0 < len) {
            block[nblock + i + 0] = block[i + 0];
            quadrant[nblock + i + 0] = 0;
        }
        if (i + 1 < len) {
            block[nblock + i + 1] = block[i + 1];
            quadrant[nblock + i + 1] = 0;
        }
    }
}
