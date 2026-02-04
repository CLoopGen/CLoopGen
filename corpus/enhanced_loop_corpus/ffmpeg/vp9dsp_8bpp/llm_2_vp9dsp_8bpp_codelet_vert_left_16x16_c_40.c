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
for (i = 0; i < 16 - 2; i += 2) {
    if (i + 1 < 16 - 2) {
        ve[i] = (top[i] + top[i + 1] + 1) >> 1;
        vo[i] = (top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2;
        ve[i + 1] = (top[i + 1] + top[i + 2] + 1) >> 1;
        vo[i + 1] = (top[i + 1] + top[i + 2] * 2 + top[i + 3] + 2) >> 2;
    } else {
        ve[i] = (top[i] + top[i + 1] + 1) >> 1;
        vo[i] = (top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2;
    }
}
}
