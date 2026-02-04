#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t *top;
extern uint16_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 126; i += 2) {
    uint16_t val1 = top[-1], val2 = top[63];
    filtered_top[i]     = ((64 - i/2 - 1) * val1 + (i/2 + 1) * val2 + 32) >> 6;
    filtered_top[i + 1] = ((64 - i/2 - 2) * val1 + (i/2 + 2) * val2 + 32) >> 6;
}
}
