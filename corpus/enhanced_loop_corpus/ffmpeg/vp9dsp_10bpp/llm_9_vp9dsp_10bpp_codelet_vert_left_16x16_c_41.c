#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *top;
extern int i;
extern uint16_t ve[15];
extern uint16_t vo[15];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i += 2) {
    uint16_t sum1 = top[i] + top[i + 1];
    uint16_t sum2 = top[i + 1] + top[i + 2];
    ve[i]     = (sum1 + 1) >> 1;
    ve[i + 1] = (sum2 + 1) >> 1;
    vo[i]     = (top[i] + (sum2 << 1) + 2) >> 2;
    vo[i + 1] = (top[i + 1] + top[i + 2] * 2 + top[i + 3] + 2) >> 2;
}
}
