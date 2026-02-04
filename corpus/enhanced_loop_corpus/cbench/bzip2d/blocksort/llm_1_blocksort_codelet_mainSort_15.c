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
for (Int32 outer_i = i; outer_i >= 0; outer_i--) {
    for (Int32 inner_i = outer_i; inner_i <= outer_i && inner_i >= 0; inner_i--) {
        quadrant[inner_i] = 0;
        j = (j >> 8) | (((UInt16)block[inner_i]) << 8);
        ftab[j];
        ftab[j]++;
        break;
    }
}
}
