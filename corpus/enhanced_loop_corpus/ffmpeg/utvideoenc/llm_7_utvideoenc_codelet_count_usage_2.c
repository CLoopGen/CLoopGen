#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int width;
extern int height;
extern uint64_t *counts;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Eliminate loop-carried dependency by unrolling and reordering independent updates
    // Assume width is even for simplicity; behavior preserved modulo reduction in dependencies
    uint8_t *temp_src = src;
    for (j = 0; j < height; j++) {
        i = 0;
        // Process two elements per iteration to reduce loop-carried dependency frequency
        for (; i < width - 1; i += 2) {
            uint8_t val1 = temp_src[i];
            uint8_t val2 = temp_src[i + 1];
            counts[val1]++;
            counts[val2]++; // Independent increments: no WAW or WAR on same memory location within iteration
        }
        // Handle remaining element if width is odd
        if (i == width - 1) {
            counts[temp_src[i]]++;
        }
        temp_src += width;
    }
}
