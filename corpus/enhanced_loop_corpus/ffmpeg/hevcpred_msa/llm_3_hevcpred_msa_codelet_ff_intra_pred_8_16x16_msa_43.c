#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *left;
extern uint8_t *filtered_left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward traversal with offset indexing to simulate different access pattern
    for (i = 0; i < 2 * 16 - 1; i++)
        filtered_left[2 * 16 - 3 - i] = (left[2 * 16 - 2 - i] + 2 * left[2 * 16 - 3 - i] + left[2 * 16 - 4 - i] + 2) >> 2;
}
