#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *top;
extern uint8_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse-order traversal with sequential access pattern
    // Iterate from the end to beginning to promote spatial locality in reverse direction
    for (i = 62; i >= 0; i--) {
        filtered_top[i] = ((64 - (i + 1)) * top[-1] + (i + 1) * top[63] + 32) >> 6;
    }
}
