#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 ftab[257];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access with temporary array to flatten indirect access
    // Precompute and store transformed indices into a local buffer to enable more predictable bhtab access
    // This changes the access pattern to be more cache-friendly by grouping updates to nearby bhtab entries.
    UInt32 temp_indices[256];
    UInt32 temp_values[256];

    for (i = 0; i < 256; i++) {
        temp_indices[i] = ftab[i] >> 5;
        temp_values[i] = 1 << (ftab[i] & 31);
    }

    // Now perform consecutive or clustered updates to bhtab
    for (i = 0; i < 256; i++) {
        bhtab[temp_indices[i]] |= temp_values[i];
    }
}
