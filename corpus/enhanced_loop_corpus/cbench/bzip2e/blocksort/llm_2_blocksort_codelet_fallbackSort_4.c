#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 ftab[257];
extern Int32 ftabCopy[256];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with step size 2, unrolling the loop to handle pairs
    for (i = 0; i < 256; i += 2) {
        if (i + 1 < 256) {
            ftabCopy[i] = ftab[i];
            ftabCopy[i + 1] = ftab[i + 1];
        } else {
            ftabCopy[i] = ftab[i];
        }
    }
}
