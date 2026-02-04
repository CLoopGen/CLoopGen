#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern int i;
extern uint8_t ve[23];
extern uint8_t vo[23];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp_even[15];
    uint8_t temp_odd[15];
    for (i = 0; i < 16 - 1; i++) {
        temp_even[i] = (top[i] + top[i + 1] + 1) >> 1;
        temp_odd[i]  = (top[i - 1] + top[i] * 2 + top[i + 1] + 2) >> 2;
    }
    for (i = 0; i < 16 - 1; i++) {
        ve[16 / 2 + i] = temp_even[i];
        vo[16 / 2 + i] = temp_odd[i];
    }
}
