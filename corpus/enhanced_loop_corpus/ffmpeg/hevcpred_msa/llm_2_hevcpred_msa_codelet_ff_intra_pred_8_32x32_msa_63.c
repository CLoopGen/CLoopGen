#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *top;
extern uint8_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step of 2 (processing every second element)
    // This changes the access pattern to non-consecutive, strided access
    for (i = 2 * 32 - 4; i >= 0; i -= 2)
        filtered_top[i] = (top[i + 1] + 2 * top[i] + top[i - 1] + 2) >> 2;
}
