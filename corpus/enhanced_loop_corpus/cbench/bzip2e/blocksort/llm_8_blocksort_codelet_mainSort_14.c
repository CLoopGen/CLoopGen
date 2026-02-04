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
    quadrant[i] = 0;
    j = (j >> 8) | (((UInt16)block[i]) << 8);
    ftab[j]++;
    quadrant[i - 1] = 0;
    j = (j >> 8) | (((UInt16)block[i - 1]) << 8);
    ftab[j]++;
    quadrant[i - 2] = 0;
    j = (j >> 8) | (((UInt16)block[i - 2]) << 8);
    ftab[j]++;
    quadrant[i - 3] = 0;
    j = (j >> 8) | (((UInt16)block[i - 3]) << 8);
    ftab[j]++;

    quadrant[i - 4] = 0;
    j = (j >> 8) | (((UInt16)block[i - 4]) << 8);
    ftab[j]++;
    quadrant[i - 5] = 0;
    j = (j >> 8) | (((UInt16)block[i - 5]) << 8);
    ftab[j]++;
    quadrant[i - 6] = 0;
    j = (j >> 8) | (((UInt16)block[i - 6]) << 8);
    ftab[j]++;
    quadrant[i - 7] = 0;
    j = (j >> 8) | (((UInt16)block[i - 7]) << 8);
    ftab[j]++;
}
}
