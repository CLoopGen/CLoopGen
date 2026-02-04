#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern uint16_t *left;
extern uint16_t *filtered_left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (accessing every second element in reverse)
    // This modifies the original pattern by skipping elements, creating a strided access pattern.
    for (i = (2 * size - 2) & ~1; i >= 0; i -= 2) {
        if (i + 1 < 2 * size - 1 && i - 1 >= 0) {
            filtered_left[i] = (left[i + 1] + 2 * left[i] + left[i - 1] + 2) >> 2;
        }
    }
    // Fill skipped indices in a second forward pass to maintain full coverage
    for (i = 1; i < 2 * size - 1; i += 2) {
        if (i + 1 < 2 * size - 1 && i - 1 >= 0) {
            filtered_left[i] = (left[i + 1] + 2 * left[i] + left[i - 1] + 2) >> 2;
        }
    }
}
