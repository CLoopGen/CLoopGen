#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *top;
extern int i;
extern uint16_t ve[7];
extern uint16_t vo[7];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t temp_e, temp_o;
    for (i = 0; i < 8 - 2; i++) {
        temp_e = (top[i] + top[i + 1] + 1) >> 1;
        temp_o = (top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2;
        ve[i] = temp_e;
        vo[i] = temp_o;
    }
}
