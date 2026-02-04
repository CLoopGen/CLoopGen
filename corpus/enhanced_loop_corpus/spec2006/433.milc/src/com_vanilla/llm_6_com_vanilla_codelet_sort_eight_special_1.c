#include <stdio.h>

#include <inttypes.h>

extern void **pt;
extern void *tt[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Introduce WAW and WAR dependencies by reordering and adding temporary variables
    // This creates loop-carried dependencies via a temporary array to simulate write-after-write
    // and write-after-read hazards artificially.
    
    void *temp[8];
    for (i = 0; i <= 3; i++) {
        temp[2 * i] = tt[2 * i];
        temp[2 * i + 1] = tt[2 * i + 1];
    }
    for (i = 0; i <= 3; i++) {
        pt[i] = temp[2 * i];           // Write depends on prior temp fill (WAW across loops)
        pt[7 - i] = temp[2 * i + 1];   // Same here, introduces inter-loop dependency
    }
}
