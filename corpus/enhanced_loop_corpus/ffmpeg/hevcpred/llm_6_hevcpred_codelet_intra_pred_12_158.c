#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t *top;
extern uint16_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < 63; j++) {
        uint16_t temp_prev = top[-1];
        uint16_t temp_curr = top[63];
        filtered_top[j] = ((64 - (j + 1)) * temp_prev + (j + 1) * temp_curr + 32) >> 6;
    }
}
