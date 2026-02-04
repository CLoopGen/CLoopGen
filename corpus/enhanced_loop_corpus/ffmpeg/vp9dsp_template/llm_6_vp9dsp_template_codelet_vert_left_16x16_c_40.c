#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern int i;
extern uint8_t ve[15];
extern uint8_t vo[15];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp_ve, temp_vo;
    for (i = 0; i < 16 - 2; i++) {
        temp_ve = (top[i] + top[i + 1] + 1) >> 1;
        temp_vo = (top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2;
        ve[i] = temp_ve;
        vo[i] = temp_vo;
    }
}
