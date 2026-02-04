#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *limit;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Int32 j;
    for (j = 0; j < 23; j++) {
        limit[j] = 0;
        limit[22 - j] = 0;
    }
}
