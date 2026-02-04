#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    left[0] = (64 * left[-1] + 32) >> 6;
    for (i = 1; i < 63; i++)
        left[i] = ((64 - (i + 1)) * left[i-1] + (i + 1) * left[63] + 32) >> 6;
}
