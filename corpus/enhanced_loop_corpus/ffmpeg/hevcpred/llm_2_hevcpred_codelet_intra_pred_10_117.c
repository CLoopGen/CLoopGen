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
    // Variant 1: Strided memory access with stride of 2 (processing every second element)
    // This changes the access pattern to non-consecutive, strided access
    // We adjust bounds accordingly to avoid out-of-bounds access
    for (i = 2 * size - 4; i >= 0; i -= 2) {
        filtered_left[i] = (left[i + 1] + 2 * left[i] + left[i - 1] + 2) >> 2;
        if (i >= 2) {
            filtered_left[i - 2] = (left[i - 1] + 2 * left[i - 2] + left[i - 3] + 2) >> 2;
        }
    }
    // Handle any remaining even-indexed elements if size is odd
    if ((2 * size - 2) % 2 == 0 && (2 * size - 2) >= 0 && (2 * size - 2) < 2 * size - 2) {
        i = 0;
        filtered_left[i] = (left[i + 1] + 2 * left[i] + left[i - 1] + 2) >> 2;
    }
}
