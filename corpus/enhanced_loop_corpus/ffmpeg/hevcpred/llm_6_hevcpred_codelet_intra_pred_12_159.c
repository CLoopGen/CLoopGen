#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t *left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t temp[63];
    for (i = 0; i < 63; i++) {
        temp[i] = ((64 - (i + 1)) * left[-1] + (i + 1) * left[63] + 32) >> 6;
    }
    for (i = 0; i < 63; i++) {
        left[i] = temp[i];
    }
}
