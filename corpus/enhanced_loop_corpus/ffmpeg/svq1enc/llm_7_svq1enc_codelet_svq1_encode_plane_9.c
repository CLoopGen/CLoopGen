#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int level;
extern int threshold[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strengthen loop-carried RAW dependency by chaining computations through a running scalar
    // This increases data dependency strictly across iterations, enforcing sequential execution.
    double accumulator = threshold[5];
    for (level = 4; level >= 0; level--) {
        accumulator = accumulator * 0.59999999999999998;
        threshold[level] = accumulator;
    }
}
