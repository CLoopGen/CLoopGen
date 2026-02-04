#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 alphaSize;
extern Int32 i;
extern Int32 j;
extern Int32 weight[516];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse Consecutive Memory Access
    for (i = alphaSize; i >= 1; i--) {
        j = weight[i] >> 8;
        j = 1 + (j / 2);
        weight[i] = j << 8;
    }
}
