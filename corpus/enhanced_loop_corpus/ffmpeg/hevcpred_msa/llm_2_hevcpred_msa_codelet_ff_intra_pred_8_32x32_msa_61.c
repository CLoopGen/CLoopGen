#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *top;
extern uint8_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride of 2 (unrolled by factor 2)
    // Access pattern: filtered_top[0], filtered_top[2], ..., top[-1] and top[63] remain fixed
    for (i = 0; i < 63; i += 2) {
        filtered_top[i] = ((63 - i) * top[-1] + (i + 1) * top[63] + 32) >> 6;
        if (i + 1 < 63) {
            filtered_top[i + 1] = ((63 - (i + 1)) * top[-1] + ((i + 1) + 1) * top[63] + 32) >> 6;
        }
    }
}
