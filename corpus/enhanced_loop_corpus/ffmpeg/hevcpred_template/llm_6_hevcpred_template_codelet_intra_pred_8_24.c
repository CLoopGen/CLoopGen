#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *top;
extern uint8_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[63];
    for (i = 0; i < 63; i++) {
        temp[i] = ((64 - (i + 1)) * top[-1] + (i + 1) * top[63] + 32) >> 6;
    }
    for (i = 0; i < 63; i++) {
        filtered_top[i] = temp[i];
    }
}
