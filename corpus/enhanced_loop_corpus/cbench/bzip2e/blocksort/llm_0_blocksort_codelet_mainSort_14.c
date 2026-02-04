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
for (; i >= 7; i -= 8) {
    for (int k = 0; k < 4; k++) {
        quadrant[i - 2*k] = 0;
        j = (j >> 8) | (((UInt16)block[i - 2*k]) << 8);
        ftab[j]++;
        quadrant[i - 2*k - 1] = 0;
        j = (j >> 8) | (((UInt16)block[i - 2*k - 1]) << 8);
        ftab[j]++;
    }
}
}
