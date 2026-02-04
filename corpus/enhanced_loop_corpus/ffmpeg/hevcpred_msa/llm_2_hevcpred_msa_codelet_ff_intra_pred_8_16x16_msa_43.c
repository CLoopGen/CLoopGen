#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *left;
extern uint8_t *filtered_left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in reverse, with adjusted bounds)
    for (i = 2 * 16 - 4; i >= 0; i -= 2)
        filtered_left[i] = (left[i + 1] + 2 * left[i] + left[i - 1] + 2) >> 2;
}
