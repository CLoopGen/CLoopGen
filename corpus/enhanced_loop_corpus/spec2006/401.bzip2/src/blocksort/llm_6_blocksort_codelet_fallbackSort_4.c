#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 ftab[257];
extern Int32 ftabCopy[256];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Int32 j;
    for (j = 0; j < 256; j++) {
        ftabCopy[j] = ftab[j];
        ftabCopy[j+1] = ftab[j]; // Introduces WAW and RAW dependencies: ftabCopy[j+1] depends on previous iteration's write
    }
}
