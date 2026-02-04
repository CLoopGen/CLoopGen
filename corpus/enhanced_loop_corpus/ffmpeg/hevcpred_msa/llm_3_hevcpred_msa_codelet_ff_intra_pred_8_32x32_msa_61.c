#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *top;
extern uint8_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access – iterate from high to low index
    // Memory access pattern reversed: filtered_top[62], filtered_top[61], ..., filtered_top[0]
    for (i = 62; i >= 0; i--) {
        filtered_top[i] = ((63 - i) * top[-1] + (i + 1) * top[63] + 32) >> 6;
    }
}
