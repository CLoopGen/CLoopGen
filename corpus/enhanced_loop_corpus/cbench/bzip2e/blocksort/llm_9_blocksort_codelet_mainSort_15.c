#include <stdio.h>

#include <inttypes.h>

typedef unsigned char UChar;

typedef unsigned short UInt16;

typedef unsigned int UInt32;

typedef int Int32;

extern UChar *block;
extern UInt16 *quadrant;
extern UInt32 *ftab;
extern Int32 i;
extern Int32 j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (Int32 k = i; k >= 0 && k >= i - 32; k--) {
    quadrant[k] = 0;
    UInt32 shifted = (j >> 8) | (((UInt16)block[k]) << 8);
    ftab[shifted]++;
    j = shifted;
    for (Int32 inner = 0; inner < 3; inner++) {
        ftab[(shifted + inner) % 65536]++;
    }
}
i = (i > 32) ? i - 33 : -1;
}
