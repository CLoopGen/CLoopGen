#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern uint16_t *top;
extern uint16_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (process every second element in reverse)
    for (i = (2 * size - 2) & ~1; i >= 0; i -= 2)
        filtered_top[i] = (top[i + 1] + 2 * top[i] + top[i - 1] + 2) >> 2;
}
