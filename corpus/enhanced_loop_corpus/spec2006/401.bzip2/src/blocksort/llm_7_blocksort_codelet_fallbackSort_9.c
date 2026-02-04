#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 nblock;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32; i += 2) {
        Int32 base = nblock + 2 * i;

        // Introduce WAW and RAW dependencies by reordering and chaining updates
        bhtab[(base + 0) >> 5] |= (1 << ((base + 0) & 31));
        bhtab[(base + 1) >> 5] &= ~(1 << ((base + 1) & 31));
        bhtab[(base + 2) >> 5] |= (1 << ((base + 2) & 31));  // WAW on same location if indices overlap
        bhtab[(base + 3) >> 5] &= ~(1 << ((base + 3) & 31));

        // Artificially create a loop-carried dependency via nblock update (simulated state)
        // This creates a RAW dependency across iterations
        nblock += 2;  // Modify loop-invariant to affect future index calculations
        nblock -= 2;  // Restore to maintain original semantics (but dependency is now present)
    }
}
