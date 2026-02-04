#include <stdio.h>

#include <inttypes.h>

extern unsigned int x[25];
extern unsigned int seed;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Introduce artificial loop-carried WAW and WAR dependencies via redundant writes and reads
    // Simulates a more tightly coupled dependency chain by re-reading and reassigning through an extra indirection.
    // Also introduces a fake dependency using a temporary array to create WAR (write-after-read) hazards.

    unsigned int temp[25];
    for (i = 0; i < 25; i++) {
        temp[i] = seed;                 // Write to temp — may cause WAR if reordered
        x[i] = temp[i];                 // Read from temp — creates WAR dependency on above
        seed *= 1313;
        seed += 88897;
        // Artificially reuse seed in a way that enforces strict ordering
        if (i > 0) {
            x[i] ^= x[i-1];             // Introduce loop-carried RAW dependency on x[i-1]
        }
    }
}
