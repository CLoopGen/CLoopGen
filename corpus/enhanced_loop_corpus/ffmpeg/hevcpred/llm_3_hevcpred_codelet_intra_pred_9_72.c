#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t *top;
extern uint16_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access on output array
    // Write to filtered_top with a stride of 2, writing 63 elements in scattered locations
    // This changes the memory access pattern to non-consecutive in the destination.
    int stride = 2;
    for (i = 0; i < 63; i++) {
        filtered_top[i * stride] = ((64 - (i + 1)) * top[-1] + (i + 1) * top[63] + 32) >> 6;
    }
}
