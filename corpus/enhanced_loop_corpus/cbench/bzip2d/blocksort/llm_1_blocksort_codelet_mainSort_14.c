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
    for (int step = 0; step < 8; step += 4) {
        int idx = i - step;
        quadrant[idx] = 0;
        j = (j >> 8) | (((UInt16)block[idx]) << 8);
        ftab[j]++;
        quadrant[idx - 1] = 0;
        j = (j >> 8) | (((UInt16)block[idx - 1]) << 8);
        ftab[j]++;
        quadrant[idx - 2] = 0;
        j = (j >> 8) | (((UInt16)block[idx - 2]) << 8);
        ftab[j]++;
        quadrant[idx - 3] = 0;
        j = (j >> 8) | (((UInt16)block[idx - 3]) << 8);
        ftab[j]++;
    }
}
}
