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
for (i = 0; i < 8 - 3; i += 2) {
    uint8_t temp1 = top[i] + top[i + 1];
    uint8_t temp2 = top[i + 1] + top[i + 2];
    ve[i] = (temp1 + 1) >> 1;
    vo[i] = (temp1 + temp2 + 2) >> 2;
    if (i + 1 < 8 - 3) {
        ve[i + 1] = (top[i + 1] + top[i + 2] + 1) >> 1;
        vo[i + 1] = (top[i + 1] + (top[i + 2] << 1) + top[i + 3] + 2) >> 2;
    }
}
}
