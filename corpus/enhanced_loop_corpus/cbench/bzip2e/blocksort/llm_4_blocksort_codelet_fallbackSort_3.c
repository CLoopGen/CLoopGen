#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

typedef unsigned char UChar;

extern Int32 nblock;
extern Int32 ftab[257];
extern Int32 i;
extern UChar *eclass8;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < nblock; i++) {
    if (eclass8[i] >= 0 && eclass8[i] < 257)
        ftab[eclass8[i]]++;
}
}
