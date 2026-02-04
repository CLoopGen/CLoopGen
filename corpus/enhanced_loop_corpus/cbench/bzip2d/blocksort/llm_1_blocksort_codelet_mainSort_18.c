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
for (; i >= 7; i -= 8) {
    for (int step = 0; step < 8; step += 4) {
        int idx = i - step;
        s = (s >> 8) | (block[idx] << 8);
        j = ftab[s] - 1;
        ftab[s] = j;
        ptr[j] = idx;
        s = (s >> 8) | (block[idx - 1] << 8);
        j = ftab[s] - 1;
        ftab[s] = j;
        ptr[j] = idx - 1;
        s = (s >> 8) | (block[idx - 2] << 8);
        j = ftab[s] - 1;
        ftab[s] = j;
        ptr[j] = idx - 2;
        s = (s >> 8) | (block[idx - 3] << 8);
        j = ftab[s] - 1;
        ftab[s] = j;
        ptr[j] = idx - 3;
    }
}
}
