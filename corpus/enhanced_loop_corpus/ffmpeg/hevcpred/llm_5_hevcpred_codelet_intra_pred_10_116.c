#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t *left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 63; ++i) {
        uint16_t temp = left[63];
        if (i < 32) {
            left[i] = ((64 - (i + 1)) * left[-1] + (i + 1) * temp + 32) >> 6;
        } else {
            left[i] = ((64 - (i + 1)) * left[-1] + (i + 1) * temp + 48) >> 6;
        }
    }
}
