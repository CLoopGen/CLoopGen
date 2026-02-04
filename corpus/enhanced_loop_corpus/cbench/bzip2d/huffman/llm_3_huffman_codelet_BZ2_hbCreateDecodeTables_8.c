#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *base;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    Int32 indices[22];
    for (Int32 j = 0; j < 22; j++) {
        indices[j] = j + 1;
    }
    for (i = 1; i < 22; i++)
        base[indices[i]] += base[indices[i] - 1];
}
