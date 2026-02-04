#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *base;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Int32 j;
    for (j = 0; j < 23; j++) {
        base[j] = 0;
        base[22 - j] = 0;
    }
}
