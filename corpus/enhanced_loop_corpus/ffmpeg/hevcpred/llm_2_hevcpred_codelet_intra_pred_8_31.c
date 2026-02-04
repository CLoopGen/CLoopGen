#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern uint8_t *left;
extern uint8_t *filtered_left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step of 2 (backward traversal with stride)
    for (i = (2 * size - 2) / 2 * 2; i >= 0; i -= 2) {
        if (i + 1 < 2 * size - 1 && i - 1 >= 0) {
            filtered_left[i] = (left[i + 1] + 2 * left[i] + left[i - 1] + 2) >> 2;
        }
    }
    // Fill in skipped indices in a second pass to maintain correctness
    for (i = (2 * size - 2) - ((2 * size - 2) % 2); i >= 1; i--) {
        if (i % 2 == 1) {
            filtered_left[i] = (left[i + 1] + 2 * left[i] + left[i - 1] + 2) >> 2;
        }
    }
}
