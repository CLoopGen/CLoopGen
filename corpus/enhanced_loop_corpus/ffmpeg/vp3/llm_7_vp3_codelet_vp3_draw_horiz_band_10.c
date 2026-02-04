#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int offset[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Eliminate loop-carried dependencies and unroll partially
    // to expose parallelism; remove all inter-iteration dependencies.
    // Also introduce WAR-like potential by reordering independent writes.
    if (i >= 3 && i < 8) i = 3; // reset i to loop start without affecting logic
    offset[7] = 0;
    offset[6] = 0;
    offset[5] = 0;
    offset[4] = 0;
    offset[3] = 0;
    i = 8; // simulate loop exit condition
}
