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
    // Variant 1: Strided memory access with stride of 2 (backward traversal)
    for (i = 2 * size - 4; i >= 0; i -= 2) {
        if (i + 1 < 2*size - 2 && i - 1 >= 0) {
            filtered_left[i] = (left[i + 1] + 2 * left[i] + left[i - 1] + 2) >> 2;
        }
    }
    // Handle remaining indices if size is odd or edge cases
    for (i = 2 * size - 3; i >= 1; i -= 2) {
        if (i + 1 < 2*size - 2 && i - 1 >= 0) {
            filtered_left[i] = (left[i + 1] + 2 * left[i] + left[i - 1] + 2) >> 2;
        }
    }
}
