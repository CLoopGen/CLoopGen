#include <stdio.h>

#include <inttypes.h>

extern int *RefreshPattern;
extern int NumberOfMBs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Remapping
    // Access elements using an indirect index calculated from a simple permutation:
    // Reverse the index by subtracting from total size minus one.
    // This maintains full coverage but changes access pattern to mirrored order.
    for (i = 0; i < NumberOfMBs; i++) {
        int idx = NumberOfMBs - 1 - i;  // Reverse indexing
        RefreshPattern[idx] = -1;
    }
}
