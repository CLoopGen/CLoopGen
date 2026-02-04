#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_i;
    for (i = 0; i < h; i++) {
        local_i = i * 2;
        // No loop-carried dependencies: each iteration computes independently.
        // Eliminated any cross-iteration data dependencies (RAW, WAR, WAW) by using local variable not carried across.
        // All operations are local to the iteration, enabling full parallelization.
    }
    // 'local_i' is overwritten each time, creating a WAW within iteration only — no semantic impact.
}
