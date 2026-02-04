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
for (i = 0; i < nblock; i += 2) {
    int i1 = i;
    int i2 = i + 1;
    if (i1 < nblock) {
        j = eclass8[i1];
        k = ftab[j] - 1;
        ftab[j] = k;
        fmap[k] = i1;
    }
    if (i2 < nblock) {
        j = eclass8[i2];
        k = ftab[j] - 1;
        ftab[j] = k;
        fmap[k] = i2;
    }
}
}
