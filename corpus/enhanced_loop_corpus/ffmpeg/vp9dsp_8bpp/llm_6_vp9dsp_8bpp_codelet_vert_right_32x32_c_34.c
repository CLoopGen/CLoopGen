#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *left;
extern int i;
extern uint8_t ve[47];
extern uint8_t vo[47];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 32 / 2 - 2; i++) {
    uint8_t temp1 = left[i * 2 + 2];
    uint8_t temp2 = left[i * 2 + 3];
    vo[i] = (left[i * 2 + 3] + temp1 * 2 + left[i * 2 + 1] + 2) >> 2;
    ve[i] = (left[i * 2 + 4] + temp2 * 2 + temp1 + 2) >> 2;
}
}
