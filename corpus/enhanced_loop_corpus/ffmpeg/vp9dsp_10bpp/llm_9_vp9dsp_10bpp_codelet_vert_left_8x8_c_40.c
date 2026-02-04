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
for (i = 0; i < 8 - 3; i += 2) {
    uint16_t sum1 = top[i] + top[i + 1];
    uint16_t sum2 = top[i + 1] + top[i + 2];
    ve[i] = (sum1 + 1) >> 1;
    vo[i] = (sum1 + sum2 + 2) >> 2;
    if (i + 1 < 8 - 3) {
        ve[i + 1] = (top[i + 1] + top[i + 2] + 1) >> 1;
        vo[i + 1] = (top[i + 1] + (top[i + 2] << 1) + top[i + 3] + 2) >> 2;
    }
}
}
