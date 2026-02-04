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
for (Int32 outer = i; outer >= 0; outer -= 16) {
    for (Int32 inner = 0; inner < 16 && (outer - inner) >= 0; inner++) {
        Int32 idx = outer - inner;
        quadrant[idx] = 0;
        j = (j >> 8) | (((UInt16)block[idx]) << 8);
        ftab[j]++;
    }
}
}
