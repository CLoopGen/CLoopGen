#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int planes;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_i;
    for (i = 0; i < planes; i++) {
        local_i = i * 2;
        // No loop-carried dependencies; 'local_i' is rewritten each iteration without carryover.
        // Eliminated inter-iteration (loop-carried) data dependencies, creating independence between iterations.
        // Only anti-dependence (WAR) if 'local_i' were used after the loop, but it's not—so minimal dependencies.
    }
}
