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
    for (i = 1; i < 32 - 1; i++) {
        ve[32 / 2 + i] = (top[i] + top[i + 1] + 1) >> 1;
        vo[32 / 2 + i] = (top[i - 1] + top[i] * 2 + top[i + 1] + 2) >> 2;
        ve[32 / 2 + i - 1] = (ve[32 / 2 + i] + ve[32 / 2 + i - 1]) >> 1; 
    }
}
