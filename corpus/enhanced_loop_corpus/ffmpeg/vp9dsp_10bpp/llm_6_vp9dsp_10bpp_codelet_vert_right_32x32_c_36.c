#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *top;
extern int i;
extern uint16_t ve[47];
extern uint16_t vo[47];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t temp_ve, temp_vo;
    for (i = 0; i < 32 - 1; i++) {
        temp_ve = (top[i] + top[i + 1] + 1) >> 1;
        temp_vo = (top[i - 1] + top[i] * 2 + top[i + 1] + 2) >> 2;
        ve[32 / 2 + i] = temp_ve;
        vo[32 / 2 + i] = temp_vo;
    }
}
