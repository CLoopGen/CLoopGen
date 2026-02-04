#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *top;
extern uint8_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 127; i += 2)
    filtered_top[i] = ((128 - (i + 1)) * top[-1] + (i + 1) * top[63] + 64) >> 7;
}
