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
    quadrant[i] = 0;
    j = (j >> 8) | (((UInt16)block[i]) << 8);
    ftab[j]++;
    if (block[i - 1] == block[i]) continue;
    quadrant[i - 1] = 0;
    j = (j >> 8) | (((UInt16)block[i - 1]) << 8);
    ftab[j]++;
    if (block[i - 2] == block[i - 1]) continue;
    quadrant[i - 2] = 0;
    j = (j >> 8) | (((UInt16)block[i - 2]) << 8);
    ftab[j]++;
    if (block[i - 3] == block[i - 2]) continue;
    quadrant[i - 3] = 0;
    j = (j >> 8) | (((UInt16)block[i - 3]) << 8);
    ftab[j]++;
}
}
