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
const Int32 stride = 4;
for (Int32 idx = i; idx >= 0; idx -= stride) {
    Int32 pos = idx % (i + 1); // Indirect access using modulo to ensure bounds
    quadrant[pos] = 0;
    j = (j >> 8) | (((UInt16)block[pos]) << 8);
    ftab[j]++;
}
}
