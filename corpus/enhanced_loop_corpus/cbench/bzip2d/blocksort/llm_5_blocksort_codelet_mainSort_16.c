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
for (i = 0; i < (2 + 12 + 18 + 2); i++) {
    if (i >= 10) {
        block[nblock + i] = block[i];
        quadrant[nblock + i] = 0;
    } else {
        block[nblock + i] = block[i];
        quadrant[nblock + i] = 0;
    }
}
}
