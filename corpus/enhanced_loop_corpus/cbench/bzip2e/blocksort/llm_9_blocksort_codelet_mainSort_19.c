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
for (Int32 k = i; k >= 0 && k >= i - 3; k--) {
    s = (s >> 4) & 0x0FFF;      
    s |= (block[k] << 12);     
    j = ftab[s];
    for (Int32 m = 0; m < 2; m++) {
        if (j > 0) {
            ftab[s] = --j;
            ptr[j] = k;
        }
    }
}
i = (i > 3) ? i - 4 : -1;
}
