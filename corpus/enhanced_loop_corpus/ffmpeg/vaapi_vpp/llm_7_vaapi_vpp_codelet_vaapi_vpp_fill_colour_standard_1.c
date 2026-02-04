#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nb_vacs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    static int accumulator = 0;
    for (i = 0; i < nb_vacs; i++) {
        accumulator += nb_vacs;
    }
    // Introduce a loop-carried dependency via static variable 'accumulator'.
    // RAW dependency: nb_vacs is read each iteration, but its value is invariant.
    // WAW dependency across iterations due to cumulative write to accumulator.
    // This creates a sequential dependency preventing full loop parallelization.
}
