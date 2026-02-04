#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef unsigned char UChar;

typedef int Int32;

typedef unsigned short UInt16;

extern UInt32 *ptr;
extern UChar *block;
extern UInt32 *ftab;
extern Int32 i;
extern Int32 j;
extern UInt16 s;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with stride of 2 (accessing every other element in reverse)
    // This changes the access pattern from sequential -1,-2,-3,-4 to strided -1,-3,i-5,i-7
    for (; i >= 6; i -= 8) {
        s = (s >> 8) | (block[i] << 8);
        j = ftab[s] - 1;
        ftab[s] = j;
        ptr[j] = i;

        s = (s >> 8) | (block[i - 2] << 8);
        j = ftab[s] - 1;
        ftab[s] = j;
        ptr[j] = i - 2;

        s = (s >> 8) | (block[i - 4] << 8);
        j = ftab[s] - 1;
        ftab[s] = j;
        ptr[j] = i - 4;

        s = (s >> 8) | (block[i - 6] << 8);
        j = ftab[s] - 1;
        ftab[s] = j;
        ptr[j] = i - 6;
    }
}
