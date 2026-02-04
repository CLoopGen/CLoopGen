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
for (i = 0; i < (2 + 12 + 18 + 2) / 2; i++) {
    Int32 idx1 = i * 2;
    Int32 idx2 = i * 2 + 1;
    block[nblock + idx1] = block[idx1];
    block[nblock + idx2] = block[idx2];
    quadrant[nblock + idx1] = 0;
    quadrant[nblock + idx2] = 0;
}
}
