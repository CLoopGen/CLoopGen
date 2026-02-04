#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t *left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t prev_value = left[-1];
    uint16_t far_value = left[63];
    for (i = 0; i < 63; i++) {
        left[i] = ((64 - (i + 1)) * prev_value + (i + 1) * far_value + 32) >> 6;
    }
}
