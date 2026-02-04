#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 ftab[257];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 128; i++) {
        UInt32 val = ftab[i];
        bhtab[(val >> 5) % 65536] ^= (1 << (val & 31)) | (1 << ((val + 16) & 31));
        bhtab[((val + 1) >> 5) % 65536] |= (1 << ((val + 1) & 31));
    }
}
