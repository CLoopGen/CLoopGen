#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t *top;
extern uint16_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 63; i += 3) {
        filtered_top[i] = ((64 - (i + 1)) * top[-1] + (i + 1) * top[63] + 32) >> 6;
        if (i + 1 < 63)
            filtered_top[i + 1] = ((64 - (i + 2)) * top[-1] + (i + 2) * top[63] + 32) >> 6;
        if (i + 2 < 63)
            filtered_top[i + 2] = ((64 - (i + 3)) * top[-1] + (i + 3) * top[63] + 32) >> 6;
    }
}
