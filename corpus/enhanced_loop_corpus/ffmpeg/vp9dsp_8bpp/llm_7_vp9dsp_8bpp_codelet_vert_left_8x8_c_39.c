#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern int i;
extern uint8_t ve[7];
extern uint8_t vo[7];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (8 - 2 > 0) {
        ve[0] = (top[0] + top[1] + 1) >> 1;
        vo[0] = (top[0] + top[1] * 2 + top[2] + 2) >> 2;
    }
    for (i = 1; i < 8 - 2; i++) {
        ve[i] = (ve[i-1] + top[i] + top[i + 1] + 1) >> 1;
        vo[i] = (vo[i-1] + top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2;
    }
}
