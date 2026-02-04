#include <stdio.h>

#include <inttypes.h>

extern int others[257];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (stride of 2), unrolling to maintain coverage
    for (i = 0; i < 257; i += 2) {
        others[i] = -1;
        if (i + 1 < 257) {
            others[i + 1] = -1;
        }
    }
}
