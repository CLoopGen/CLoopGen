#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *top;
extern int i;
extern uint16_t ve[23];
extern uint16_t vo[23];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t temp_even, temp_odd;
    for (i = 0; i < 16 - 1; i++) {
        temp_even = (top[i] + top[i + 1] + 1) >> 1;
        temp_odd = (top[i - 1] + top[i] * 2 + top[i + 1] + 2) >> 2;
        ve[16 / 2 + i] = temp_even;
        vo[16 / 2 + i] = temp_odd;
    }
}
