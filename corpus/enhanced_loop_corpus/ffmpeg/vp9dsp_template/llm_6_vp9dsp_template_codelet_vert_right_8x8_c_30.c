#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *left;
extern int i;
extern uint8_t ve[11];
extern uint8_t vo[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8 / 2 - 2; i++) {
    uint8_t temp1 = left[i * 2 + 3];
    uint8_t temp2 = left[i * 2 + 2];
    uint8_t temp3 = left[i * 2 + 1];
    vo[i] = (temp1 + temp2 * 2 + temp3 + 2) >> 2;
    uint8_t temp4 = left[i * 2 + 4];
    ve[i] = (temp4 + temp1 * 2 + temp2 + 2) >> 2;
}
}
