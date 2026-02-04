#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern int i;
extern uint8_t ve[31];
extern uint8_t vo[31];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp_even;
    for (i = 0; i < 32 - 2; i++) {
        temp_even = (top[i] + top[i + 1] + 1) >> 1;
        ve[i] = temp_even;
        vo[i] = (top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2;
    }
}
