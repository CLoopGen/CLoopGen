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



void loop(){
    // Variant 2: Increased computational intensity with unrolled additional iterations and redundant bit manipulation
    for (; i >= 7; i -= 8) {
        // First group of 4 (original pattern, unrolled twice)
        s = (s >> 8) | (block[i] << 8);
        j = ftab[s] - 1;
        ftab[s] = j;
        ptr[j] = i;

        s = (s >> 8) | (block[i - 1] << 8);
        j = ftab[s] - 1;
        ftab[s] = j;
        ptr[j] = i - 1;

        s = (s >> 8) | (block[i - 2] << 8);
        j = ftab[s] - 1;
        ftab[s] = j;
        ptr[j] = i - 2;

        s = (s >> 8) | (block[i - 3] << 8);
        j = ftab[s] - 1;
        ftab[s] = j;
        ptr[j] = i - 3;

        // Second group of 4
        s = (s >> 8) | (block[i - 4] << 8);
        j = ftab[s] - 1;
        ftab[s] = j;
        ptr[j] = i - 4;

        s = (s >> 8) | (block[i - 5] << 8);
        j = ftab[s] - 1;
        ftab[s] = j;
        ptr[j] = i - 5;

        s = (s >> 8) | (block[i - 6] << 8);
        j = ftab[s] - 1;
        ftab[s] = j;
        ptr[j] = i - 6;

        s = (s >> 8) | (block[i - 7] << 8);
        j = ftab[s] - 1;
        ftab[s] = j;
        ptr[j] = i - 7;

        // Extra computation to increase intensity: reprocess middle elements with alternate shift
        UInt16 t = (block[i - 3] << 8) | block[i - 2];
        j = ftab[t] - 1;
        ftab[t] = j;
        ptr[j] = i - 3; // reuse index
    }
}
