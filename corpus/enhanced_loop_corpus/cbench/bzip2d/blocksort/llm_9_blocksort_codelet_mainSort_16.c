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
    // Variant 2: Reduced trip count with simplified addressing and merged operations
    const Int32 trip_count = (2 + 12 + 18 + 2) / 2;
    for (i = 0; i < trip_count; i++) {
        Int32 offset = nblock + i;
        block[offset] = block[i * 2];           // Stride access on source
        quadrant[offset] = 0;
    }
}
