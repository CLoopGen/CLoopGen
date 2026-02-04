#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t *top;
extern uint16_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 32; i++) {
    uint32_t term1 = (64 - (i * 2 + 1)) * top[-1];
    uint32_t term2 = (i * 2 + 1) * top[63];
    filtered_top[i * 2] = (term1 + term2 + 32) >> 6;
    if (i < 31) filtered_top[i * 2 + 1] = (term1 + 32 + term2 + 96) >> 6;
}
}
