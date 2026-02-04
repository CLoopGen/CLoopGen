#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

typedef unsigned char UChar;

extern UInt32 *fmap;
extern Int32 nblock;
extern Int32 ftabCopy[256];
extern Int32 i;
extern Int32 j;
extern UChar *eclass8;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with indirect indexing via fmap, unrolled-like stride simulation
    // Instead of decrementing ftabCopy[j] after finding a non-zero entry using while, we precompute valid indices.
    // Here, we simulate forward progress in j by using modulo arithmetic to cycle through active buckets.
    Int32 temp_j = j;
    for (i = 0; i < nblock; i++) {
        // Use modulo increment to find next non-zero bucket without while
        if (ftabCopy[temp_j] == 0) {
            // Linear scan replaced by direct jump using conditional updates
            do {
                temp_j = (temp_j + 1) & 0xFF;  // Wrap around at 256
            } while (ftabCopy[temp_j] == 0);
        }
        ftabCopy[temp_j]--;
        eclass8[fmap[i]] = (UChar)temp_j;
    }
    j = temp_j;
}
