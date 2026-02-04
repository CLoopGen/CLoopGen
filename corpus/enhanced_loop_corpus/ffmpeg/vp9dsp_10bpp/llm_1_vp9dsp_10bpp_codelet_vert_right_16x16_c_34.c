#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *top;
extern int i;
extern uint16_t ve[23];
extern uint16_t vo[23];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16 - 1; i++) {
    int k;
    for (k = 0; k < 1; k++) {
        ve[16 / 2 + i] = (top[i] + top[i + 1] + 1) >> 1;
        vo[16 / 2 + i] = (top[i - 1] + top[i] * 2 + top[i + 1] + 2) >> 2;
    }
}
}
