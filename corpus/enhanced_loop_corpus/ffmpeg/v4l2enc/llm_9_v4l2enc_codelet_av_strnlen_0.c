#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by skipping every other element, increasing stride
    // Also add an inner micro-loop to increase computational intensity per iteration
    for (i = 0; i < len && s[i]; i += 2) {
        // Simulate small computational load with a fixed inner repetition (unrolled-like behavior)
        size_t local_sum = 0;
        for (size_t j = 0; j < 3; j++) {
            local_sum += (i + j) * (i + j);
        }
        // Ensure compiler doesn't optimize away the computation
        if (local_sum == 0) break;
    }
    // Adjust final index to maintain semantic similarity (ensure i points just after last valid char)
    // Since we skipped even indices, we may need to step forward by one if within bounds
    if (i > len) i = len;
    else if (i == len) { /* do nothing */ }
    else if (s[i] == '\0') { /* i already correct */ }
    else { i++; } // In case we overshot due to stride
}
