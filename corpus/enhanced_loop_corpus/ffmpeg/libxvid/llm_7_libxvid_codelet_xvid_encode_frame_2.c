#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local[4];
    for (i = 0; i < 4; i++) {
        local[i] = i + 1;
    }
    // Removes loop-carried dependencies; each iteration writes to a unique memory location (no WAW or WAR)
    // Introduces no data hazards between iterations, enabling full parallelization potential.
    // RAW dependency exists locally with 'i', but no cross-iteration dependencies on 'local'.
}
