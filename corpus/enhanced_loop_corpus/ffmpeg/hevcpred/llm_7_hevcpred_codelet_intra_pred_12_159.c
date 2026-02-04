#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t *left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t prev_val = left[-1];
    uint16_t next_val = left[63];
    for (i = 0; i < 63; i++) {
        left[i] = ((64 - (i + 1)) * prev_val + (i + 1) * next_val + 32) >> 6;
    }
}
