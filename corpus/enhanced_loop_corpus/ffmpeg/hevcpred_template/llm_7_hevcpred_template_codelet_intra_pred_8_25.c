#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint8_t prev_val = left[-1];
uint8_t future_val = left[63];
for (i = 0; i < 63; i++) {
    left[i] = ((64 - (i + 1)) * prev_val + (i + 1) * future_val + 32) >> 6;
}
}
