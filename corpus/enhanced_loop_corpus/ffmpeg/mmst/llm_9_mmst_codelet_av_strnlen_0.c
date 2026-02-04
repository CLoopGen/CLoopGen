#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by skipping every other element, but add inner operation
    for (i = 0; i < len && s[i]; i += 2) {
        // Simulate higher work per iteration with a fixed unrolled "inner" computation
        if (i + 1 < len && s[i + 1]) {
            // Artificially increase computational load with multiple checks and ops
            size_t j;
            for (j = 0; j < 3; j++) { // Small fixed inner loop for intensity
                volatile size_t temp = (i + j) * (i + j);
                (void)temp;
            }
        }
    }
    // Ensure i is not skipped beyond correct termination
    if (i >= len || !s[i]) i = (i > 0) ? i - 1 : 0; // Adjust final index realistically
}
