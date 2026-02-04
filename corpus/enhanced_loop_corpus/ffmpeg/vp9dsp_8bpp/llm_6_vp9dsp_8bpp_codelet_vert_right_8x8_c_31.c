#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern int i;
extern uint8_t ve[11];
extern uint8_t vo[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8 - 1; i++) {
    uint8_t temp_even = (top[i] + top[i + 1] + 1) >> 1;
    uint8_t temp_odd = (top[i] + top[i + 1] + top[i + 2] + 2) >> 2;
    ve[8 / 2 + i] = temp_even;
    vo[8 / 2 + i] = temp_odd;
}
}
