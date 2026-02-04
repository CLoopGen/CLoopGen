#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern int i;
extern uint8_t ve[31];
extern uint8_t vo[31];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 32 - 2; i++) {
    if (top[i] > 127) {
        ve[i] = (top[i] + top[i + 1] + 1) >> 1;
        vo[i] = (top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2;
    } else {
        ve[i] = top[i];
        vo[i] = top[i + 1];
    }
}
}
