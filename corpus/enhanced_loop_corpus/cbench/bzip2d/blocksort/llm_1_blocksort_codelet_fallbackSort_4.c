#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 ftab[257];
extern Int32 ftabCopy[256];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (Int32 j = 0; j < 256; j += 16) {
        for (Int32 k = j; k < j + 16 && k < 256; k++)
            ftabCopy[k] = ftab[k];
    }
}
