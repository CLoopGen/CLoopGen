#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *left;
extern int i;
extern uint16_t ve[11];
extern uint16_t vo[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8 / 2 - 3; i += 1) {
    uint16_t temp1 = left[i * 2 + 2];
    uint16_t temp2 = left[i * 2 + 3];
    vo[i] = (left[i * 2 + 1] + temp1 + temp1 + left[i * 2 + 3]) >> 2;
    ve[i] = (temp1 + temp2 + temp2 + left[i * 2 + 4] + 1) >> 2;
}
}
