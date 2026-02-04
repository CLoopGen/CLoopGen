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
for (; i >= 0; i--) {
    s = (s >> 8) | (block[i] << 8);
    j = ftab[s] - 1;
    ftab[s] = j;
    ptr[j] = i;
}

}
