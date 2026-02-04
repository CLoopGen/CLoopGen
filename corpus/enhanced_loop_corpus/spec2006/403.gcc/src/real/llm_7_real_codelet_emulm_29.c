#include <stdio.h>

#include <inttypes.h>

extern unsigned short equot[9];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Eliminate all loop-carried dependencies by unrolling and using independent indices.
    // Each assignment is independent, removing any potential RAW, WAR, or WAW dependencies across iterations.
    // This enables full parallelization.

    equot[2] = 0;
    equot[3] = 0;
    equot[4] = 0;
    equot[5] = 0;
    equot[6] = 0;
    equot[7] = 0;
    equot[8] = 0;
}
