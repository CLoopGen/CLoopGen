#include <stdio.h>

#include <inttypes.h>

extern int influence[400];
extern int ii;
extern int k;
extern int queue[400];
extern int queue_end;
extern int working[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse Indirect Memory Access Pattern
    // Traverse the queue in reverse order to change access pattern from forward to backward indirect indexing.
    // This alters cache behavior and memory access locality.

    for (k = queue_end - 1; k >= 0; k--) {
        ii = queue[k];
        if (working[ii] > (((int)((0.02) * (1 << 12)) + 0.5)) || influence[ii] == 0)
            influence[ii] += working[ii];
        working[ii] = 0;
    }
}
