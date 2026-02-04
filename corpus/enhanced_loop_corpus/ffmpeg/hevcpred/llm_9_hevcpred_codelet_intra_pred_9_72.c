#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t *top;
extern uint16_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32; i++) {
        filtered_top[i] = ((63 - i) * top[-1] + (i + 1) * top[63] + 32) >> 6;
        filtered_top[63 - i] = ((i + 1) * top[-1] + (63 - i) * top[63] + 32) >> 6;
    }
    // Handle middle element if needed, but original range is fixed
}
