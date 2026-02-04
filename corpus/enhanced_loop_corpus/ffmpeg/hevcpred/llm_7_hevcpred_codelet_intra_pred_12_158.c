#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t *top;
extern uint16_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int k;
    uint16_t cache_prev = top[-1];
    uint16_t cache_curr = top[63];
    for (k = 0; k < 63; k++) {
        filtered_top[k] = ((64 - (k + 1)) * cache_prev + (k + 1) * cache_curr + 32) >> 6;
    }
}
