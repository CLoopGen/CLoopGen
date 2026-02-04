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
        UInt32 val_low = ftab[i];
        UInt32 val_high = ftab[255 - i];
        bhtab[val_low >> 5] |= (1 << (val_low & 31));
        bhtab[val_high >> 5] |= (1 << (val_high & 31));
    }
}
