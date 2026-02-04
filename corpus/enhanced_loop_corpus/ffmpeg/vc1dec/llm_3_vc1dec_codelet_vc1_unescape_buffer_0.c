#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int size;
extern uint8_t *dst;
extern int dsize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive Forward and Reverse Access Pattern
    // Phase 1: Forward traversal with consecutive access for even indices
    for (i = 0; i < size; i++) {
        uint8_t *current = src + i;
        if ((i % 2) == 0) {  // Even indices: process forward
            if (current[0] == 3 && i >= 2 && !(current[-1]) && !(current[-2]) && i < size - 1 && current[1] < 4) {
                dst[dsize++] = current[1];
                i++;  // Skip next index
            } else {
                dst[dsize++] = *current;
            }
        }
    }

    // Phase 2: Reverse traversal for odd indices to create mixed access pattern
    for (i = size - 1; i >= 0; i--) {
        if ((i % 2) == 1) {  // Odd indices only
            uint8_t *current = src + i;
            if (current[0] == 3 && i >= 2 && !(current[-1]) && !(current[-2]) && i < size - 1 && current[1] < 4) {
                // In reverse, we still append in logical order
                dst[dsize++] = current[1];
                i--;  // Simulate skip in reverse logic (adjusted via loop control)
            } else {
                dst[dsize++] = *current;
            }
        }
    }
}
