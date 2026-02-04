#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t *top;
extern uint16_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 62; i >= 0; i--)
        filtered_top[i] = ((65 - i) * top[-1] + (62 - i + 2) * top[63] + 32) >> 6;
}
