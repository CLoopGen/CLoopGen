#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t *top;
extern uint16_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 63; i++) {
        uint16_t weight = i + 1;
        uint32_t temp = (64 - weight) * top[-1] + weight * top[63];
        if ((temp + 32) & 0x40) {
            filtered_top[i] = (temp + 32) >> 6;
        } else {
            filtered_top[i] = (temp + 64) >> 6;
        }
    }
}
