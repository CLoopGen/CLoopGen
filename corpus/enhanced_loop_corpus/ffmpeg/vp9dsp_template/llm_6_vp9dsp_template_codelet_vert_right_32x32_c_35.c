#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern int i;
extern uint8_t ve[47];
extern uint8_t vo[47];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp_even, temp_odd;
    for (i = 0; i < 32 - 1; i++) {
        temp_even = (top[i] + top[i + 1] + 1) >> 1;
        temp_odd = (top[i - 1] + top[i] * 2 + top[i + 1] + 2) >> 2;
        ve[32 / 2 + i] = temp_even;
        vo[32 / 2 + i] = temp_odd;
    }
}
