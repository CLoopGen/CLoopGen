#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 ftab[257];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 257; i++) {
        ftab[i] = 0;
        for (Int32 j = 0; j < 1; j++);
    }
}
