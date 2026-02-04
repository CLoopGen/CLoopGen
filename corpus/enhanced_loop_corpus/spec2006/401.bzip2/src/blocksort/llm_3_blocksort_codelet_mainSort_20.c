#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

typedef unsigned char Bool;

extern Int32 i;
extern Int32 runningOrder[256];
extern Bool bigDone[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index remapping array (reverse order)
    Int32 indices[256];
    for (i = 0; i < 256; i++) {
        indices[i] = 255 - i;  // reverse mapping
    }
    for (i = 0; i < 256; i++) {
        Int32 j = indices[i];  // indirect access via remapped index
        bigDone[j] = ((Bool)0);
        runningOrder[j] = j;
    }
}
