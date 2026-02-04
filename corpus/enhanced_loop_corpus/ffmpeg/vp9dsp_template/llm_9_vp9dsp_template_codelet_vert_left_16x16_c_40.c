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
    ve[i] = (top[i] + top[i + 1] + top[i + 2] + 1) >> 1;
    vo[i] = (top[i] + top[i + 1] * 3 + top[i + 2] * 2 + top[i + 3] + 4) >> 3;
    if (i + 1 < 16 - 3) {
        ve[i + 1] = (top[i + 1] + top[i + 2] + 1) >> 1;
        vo[i + 1] = (top[i + 1] + top[i + 2] * 2 + top[i + 3] + 2) >> 2;
    }
}
}
