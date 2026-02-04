#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned short local_val = 0;
    for (i = 0; i < 6 - 2; i++) {
        *(x + i) = local_val; // Eliminate pointer update side effect; remove WAR/WAW via direct indexing
                              // No loop-carried data dependency; all writes are independent
    }
    // Final write to maintain some observable effect
    *x = *x; // Trivial self-read/write to preserve liveness if optimized
}
