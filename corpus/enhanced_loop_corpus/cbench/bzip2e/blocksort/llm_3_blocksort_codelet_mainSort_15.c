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
UInt32 indices[4] = {i, i-1, i-2, i-3};
for (Int32 idx = 0; i >= 0 && idx < 4; idx++) {
    Int32 pos = indices[idx];
    if (pos >= 0) {
        quadrant[pos] = 0;
        j = (j >> 8) | (((UInt16)block[pos]) << 8);
        ftab[j]++;
    }
    if (idx == 3) {
        i -= 4;
        indices[0] = i; indices[1] = i-1; indices[2] = i-2; indices[3] = i-3;
        idx = -1;
    }
}
}
