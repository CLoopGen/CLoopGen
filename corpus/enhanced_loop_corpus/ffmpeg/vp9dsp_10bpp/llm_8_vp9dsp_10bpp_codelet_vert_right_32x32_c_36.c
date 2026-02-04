#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *top;
extern int i;
extern uint16_t ve[47];
extern uint16_t vo[47];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i++) {
    ve[16 + i] = (top[i] + top[i + 2] + 1) >> 1;
    vo[16 + i] = (top[i] + top[i + 1] * 2 + 3) >> 2;
}
}
