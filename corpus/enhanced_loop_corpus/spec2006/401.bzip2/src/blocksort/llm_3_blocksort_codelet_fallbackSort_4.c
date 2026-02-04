#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 ftab[257];
extern Int32 ftabCopy[256];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access — copy from the end to the beginning
    for (i = 255; i >= 0; i--) {
        ftabCopy[i] = ftab[i];
    }
}
