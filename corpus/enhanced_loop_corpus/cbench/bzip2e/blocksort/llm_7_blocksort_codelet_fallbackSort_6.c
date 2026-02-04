#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

typedef unsigned char UChar;

extern UInt32 *fmap;
extern Int32 nblock;
extern Int32 ftab[257];
extern Int32 i;
extern Int32 j;
extern Int32 k;
extern UChar *eclass8;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Int32 local_ftab[257];
    for (i = 0; i < 257; i++) {
        local_ftab[i] = ftab[i];
    }
    for (i = 0; i < nblock; i++) {
        j = eclass8[i];
        k = local_ftab[j] - 1;
        local_ftab[j] = k;
        fmap[k] = i;
    }
    for (i = 0; i < 257; i++) {
        ftab[i] = local_ftab[i];
    }
}
