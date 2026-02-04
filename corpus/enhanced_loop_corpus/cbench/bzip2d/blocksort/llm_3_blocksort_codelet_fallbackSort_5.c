#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 ftab[257];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access using an index array to simulate permutation
    Int32 idx[256];
    for (Int32 k = 0; k < 256; k++)
        idx[k] = k + 1;  // idx holds indices 1..256

    // Process in reverse order of the index array (reverse traversal)
    for (Int32 k = 255; k >= 0; k--) {
        Int32 pos = idx[k];
        if (pos > 0)
            ftab[pos] += ftab[pos - 1];
    }
}
