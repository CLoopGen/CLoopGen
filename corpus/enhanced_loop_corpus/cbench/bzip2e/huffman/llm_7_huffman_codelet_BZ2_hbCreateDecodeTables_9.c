#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *limit;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Int32 j;
    for (i = 0, j = 22; i < 23; i++, j--) {
        limit[i] = 0;
        limit[j] = 0;
    }
}
