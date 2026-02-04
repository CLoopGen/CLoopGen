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
for (i = 0; i < (2 + 12 + 18 + 2) * 2; i += 2) {
    block[nblock + i] = block[i];
    block[nblock + i + 1] = block[i + 1];
    quadrant[nblock + i] = 0;
    quadrant[nblock + i + 1] = 0;
}
}
