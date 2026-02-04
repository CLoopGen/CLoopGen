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
for (i = 1; i < 32 - 2; i++) {
    ve[i] = (ve[i-1] + top[i] + top[i + 1] + 1) >> 1;
    vo[i] = (top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2;
}
ve[0] = (top[0] + top[1] + 1) >> 1;
vo[0] = (top[0] + top[1] * 2 + top[2] + 2) >> 2;
}
