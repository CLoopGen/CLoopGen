#include <stdio.h>

#include <inttypes.h>

extern int x;
extern int *iE;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < 26; x += 4) {
        iE[x]     = 0;
        if (x + 1 < 26) iE[x + 1] = 0;
        if (x + 2 < 26) iE[x + 2] = 0;
        if (x + 3 < 26) iE[x + 3] = 0;
    }
    // Eliminated potential loop-carried dependencies by unrolling
    // Increased instruction-level parallelism; no inter-iteration dependencies
}
