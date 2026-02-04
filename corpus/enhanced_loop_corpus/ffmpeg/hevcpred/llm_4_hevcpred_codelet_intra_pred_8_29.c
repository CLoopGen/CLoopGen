#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *top;
extern uint8_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 63; i++) {
        if ((i & 1) == 0) {
            filtered_top[i] = ((64 - (i + 1)) * top[-1] + (i + 1) * top[63] + 32) >> 6;
        } else {
            filtered_top[i] = ((64 - (i + 1)) * top[-1] + (i + 1) * top[63] + 48) >> 6;
        }
    }
}
