#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *base;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    Int32 indices[23];
    for (i = 0; i < 23; i++)
        indices[i] = i;  // Populate direct mapping (could be randomized or reordered in real use cases)
    for (i = 0; i < 23; i++)
        base[indices[i]] = 0;
}
