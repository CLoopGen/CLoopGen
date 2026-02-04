#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 ftab[257];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 257; i++) {
        for (Int32 j = 0; j < 1; j++) {
            ftab[i] += ftab[i - 1];
        }
    }
}
