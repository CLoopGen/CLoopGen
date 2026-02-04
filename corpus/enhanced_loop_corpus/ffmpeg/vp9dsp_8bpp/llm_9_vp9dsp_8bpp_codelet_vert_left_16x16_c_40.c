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
for (i = 0; i < 16 - 3; i += 2) {
    uint8_t sum1 = top[i] + top[i + 1];
    uint8_t sum2 = top[i + 1] + top[i + 2];
    ve[i]   = (sum1 + 1) >> 1;
    vo[i]   = (sum1 + sum2 + 2) >> 2;
    ve[i+1] = (sum2 + 1) >> 1;
    vo[i+1] = (sum2 + top[i + 3] + 2) >> 2;
}
}
