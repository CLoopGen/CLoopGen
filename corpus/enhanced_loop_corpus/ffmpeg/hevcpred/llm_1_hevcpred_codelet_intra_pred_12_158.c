#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t *top;
extern uint16_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 7; i++) {
    int base = i * 9;
    int end = (i + 1) * 9;
    if (end > 63) end = 63;
    for (int k = base; k < end; k++)
        filtered_top[k] = ((64 - (k + 1)) * top[-1] + (k + 1) * top[63] + 32) >> 6;
}
}
