#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern int i;
extern uint8_t ve[11];
extern uint8_t vo[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16 - 2; i++) {
    ve[8 / 2 + i % 6] = (top[i] + top[i + 1] + top[(i + 2) % 32] + 2) >> 2;
    vo[8 / 2 + i % 6] = (top[i] * 3 + top[i + 1] * 2 + top[i + 2] + 3) >> 3;
}
}
