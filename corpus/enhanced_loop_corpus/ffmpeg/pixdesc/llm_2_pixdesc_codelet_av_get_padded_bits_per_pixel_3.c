#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int c;
extern int bits;
extern int steps[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in a conceptual larger array)
    // Here, we simulate a strided access pattern by accessing steps with a stride of 2,
    // but only if the index is even and within bounds. This creates non-unit stride behavior.
    for (c = 0; c < 4; c += 2) {
        bits += steps[c];
        if (c + 1 < 4) {
            bits += steps[c + 1];  // Emulate unrolled strided access without changing logic
        }
    }
}
