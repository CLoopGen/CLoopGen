#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int level;
extern int threshold[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce additional temporary variable to break direct WAW and create intra-iteration dependency
    // This variant removes the strict loop-carried WAW dependency by using a temp array,
    // thus enabling potential parallelization or reordering.
    double temp[6];
    temp[5] = threshold[5]; // Initialize base value
    for (level = 4; level >= 0; level--) {
        temp[level] = temp[level + 1] * 0.59999999999999998;
    }
    // Write back to original array after computation to eliminate loop-carried WAW
    for (level = 4; level >= 0; level--) {
        threshold[level] = temp[level];
    }
}
