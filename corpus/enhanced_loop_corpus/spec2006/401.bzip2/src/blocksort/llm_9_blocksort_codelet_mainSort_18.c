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
for (; i >= 1; i -= 2) {
    UInt32 temp1 = block[i];
    UInt32 temp2 = block[i - 1];
    s = (s >> 8) | (temp1 << 8);
    j = ftab[s] - 1;
    ftab[s] = j;
    ptr[j] = i;
    s = (s >> 8) | (temp2 << 8);
    j = ftab[s] - 1;
    ftab[s] = j;
    ptr[j] = i - 1;
}
}
