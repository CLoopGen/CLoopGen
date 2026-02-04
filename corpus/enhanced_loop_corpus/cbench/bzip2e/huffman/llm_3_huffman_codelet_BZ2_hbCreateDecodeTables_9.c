#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *limit;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated statically)
    Int32 indices[23];
    for (i = 0; i < 23; i++)
        indices[i] = i;  // Populate index map (could be randomized or reordered in real use)
    for (i = 0; i < 23; i++)
        limit[indices[i]] = 0;
}
