#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t *top;
extern uint16_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (stride of 2) with bounds-safe indexing
    for (i = 0; i < 32; i++) {
        int idx = 2 * i;
        filtered_top[idx] = ((64 - (i + 1)) * top[-1] + (i + 1) * top[63] + 32) >> 6;
        if (idx + 1 < 63) {
            filtered_top[idx + 1] = ((64 - (i + 2)) * top[-1] + (i + 2) * top[63] + 32) >> 6;
        }
    }
}
