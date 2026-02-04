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
    for (i = nblock - 1; i >= 0; i--) {
        ftab[eclass8[i]] = ftab[eclass8[i]] + 1;
    }
}
