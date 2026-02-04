#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *top;
extern  uint16_t *left;
extern int i;
extern uint16_t v[63];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i++) {
    uint32_t sum_left = (uint32_t)left[i] + (uint32_t)left[i + 16] + 
                        ((uint32_t)left[i + 1] << 1) + ((uint32_t)left[i + 17] << 1);
    uint32_t sum_top = (uint32_t)top[i] + (uint32_t)top[i + 16] + 
                       ((uint32_t)top[i + 1] << 1) + ((uint32_t)top[i + 17] << 1);
    v[i] = (sum_left + 4) >> 3;
    v[32 + 1 + i] = (sum_top + 4) >> 3;
}
}
