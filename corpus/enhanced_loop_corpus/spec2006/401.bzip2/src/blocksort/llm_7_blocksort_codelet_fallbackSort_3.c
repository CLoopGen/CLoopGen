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
    Int32 j;
    for (i = 0; i < nblock; i++) {
        j = eclass8[i];
        ftab[j]++;
        ftab[j]++; // Introduce WAW and WAR dependency on ftab[j]
        ftab[j]--;
    }
}
