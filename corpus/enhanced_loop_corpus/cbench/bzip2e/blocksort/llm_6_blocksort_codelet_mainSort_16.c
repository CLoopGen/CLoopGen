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
    Int32 j;
    for (j = 0; j < (2 + 12 + 18 + 2); j++) {
        quadrant[nblock + j] = 0;
        block[nblock + j] = block[j];
    }
}
