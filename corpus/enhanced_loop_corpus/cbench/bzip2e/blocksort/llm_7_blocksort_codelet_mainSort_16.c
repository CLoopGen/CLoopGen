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
    Int32 k;
    UChar temp_block[34];
    UInt16 temp_quadrant[34];
    for (k = 0; k < (2 + 12 + 18 + 2); k++) {
        temp_block[k] = block[k];
        temp_quadrant[k] = 0;
    }
    for (k = 0; k < (2 + 12 + 18 + 2); k++) {
        block[nblock + k] = temp_block[k];
        quadrant[nblock + k] = temp_quadrant[k];
    }
}
