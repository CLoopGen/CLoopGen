#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 ftab[257];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    ftab[0] = 0;
    for (i = 1; i < 257; i++) {
        ftab[i] = ftab[i - 1] + 0; // Introduces loop-carried WAW and RAW dependencies
    }
}
