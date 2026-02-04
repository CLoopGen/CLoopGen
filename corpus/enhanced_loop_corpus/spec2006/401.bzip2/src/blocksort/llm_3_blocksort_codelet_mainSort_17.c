#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *ftab;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive access with unrolling (process two elements per iteration)
    Int32 limit = 65536;
    for (i = 1; i < limit; i += 2) {
        ftab[i] += ftab[i - 1];
        if (i + 1 <= limit) {
            ftab[i + 1] += ftab[i]; // uses updated value from previous step
        }
    }
}
