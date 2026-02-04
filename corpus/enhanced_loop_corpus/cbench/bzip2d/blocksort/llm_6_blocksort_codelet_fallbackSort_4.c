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
        ftab[j + 1] = ftab[j] + 1; // Introduce WAW and RAW loop-carried dependencies
    }
}
