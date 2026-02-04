#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *ftab;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive write with indirect read using an index array (simulated via arithmetic)
    // Simulating indirect access by accessing ftab with an offset pattern (i >> 1)
    for (i = 1; i <= 65536; i++) {
        if (i > 1 && (i & 1)) {  // Only update on odd indices, reading from a compressed index
            Int32 idx = i >> 1;  // Indirect-like index calculation
            ftab[i] += ftab[idx];
        }
    }
}
