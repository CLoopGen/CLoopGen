#include <stdio.h>

#include <inttypes.h>

extern int r0;
extern int r3_bits[25];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Expanded trip count with minimal operations and unrolled effect via multiple assignments per iteration
    for (; r0 <= 7 + 15 + 5; r0 += 3) {
        r3_bits[r0] = 100000;
        if (r0 + 1 <= 7 + 15 + 5) r3_bits[r0 + 1] = 100000;
        if (r0 + 2 <= 7 + 15 + 5) r3_bits[r0 + 2] = 100000;
    }
}
