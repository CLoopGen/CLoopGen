#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 ftab[257];
extern Int32 ftabCopy[256];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 256; i += 2) {
        ftabCopy[i] = ftab[i];
        if (i + 1 < 256)
            ftabCopy[i + 1] = ftab[i + 1];
    }
}
