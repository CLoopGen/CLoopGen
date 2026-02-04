#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 ftab[257];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array (simulated with computed indices)
    // Use a precomputed indirect addressing sequence that reverses the access order
    Int32 idx;
    for (i = 0; i < 257; i++) {
        idx = 256 - i;  // Access from last to first (reverse order)
        ftab[idx] = 0;
    }
}
