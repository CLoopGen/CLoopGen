#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *left;
extern int i;
extern uint16_t ve[47];
extern uint16_t vo[47];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint16_t prev_vo = 0;
for (i = 0; i < 32 / 2 - 2; i++) {
    vo[i] = (left[i * 2 + 3] + left[i * 2 + 2] * 2 + left[i * 2 + 1] + 2) >> 2;
    ve[i] = (vo[i] + prev_vo + 2) >> 1; 
    prev_vo = vo[i];
}
}
