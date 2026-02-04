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
for (i = 0; i < 16; i++) {
    uint16_t temp1 = left[i * 2 + 3] + left[i * 2 + 2];
    uint16_t temp2 = left[i * 2 + 1] + left[i * 2 + 4];
    vo[i] = (temp1 + temp1 + left[i * 2 + 1] + 2) >> 2;
    ve[i] = (temp2 + left[i * 2 + 3] * 2 + 2) >> 2;
}
}
