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
for (; i >= 3; i -= 4) {
    UInt16 temp_j1 = (j >> 8) | (((UInt16)block[i]) << 8);
    ftab[temp_j1]++;
    quadrant[i] = 0;

    UInt16 temp_j2 = (temp_j1 >> 8) | (((UInt16)block[i - 1]) << 8);
    ftab[temp_j2]++;
    quadrant[i - 1] = 0;

    UInt16 temp_j3 = (temp_j2 >> 8) | (((UInt16)block[i - 2]) << 8);
    ftab[temp_j3]++;
    quadrant[i - 2] = 0;

    UInt16 temp_j4 = (temp_j3 >> 8) | (((UInt16)block[i - 3]) << 8);
    ftab[temp_j4]++;
    quadrant[i - 3] = 0;

    j = temp_j4;
}
}
