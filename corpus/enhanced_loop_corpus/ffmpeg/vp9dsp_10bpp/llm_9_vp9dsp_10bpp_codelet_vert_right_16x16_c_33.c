#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *left;
extern int i;
extern uint16_t ve[23];
extern uint16_t vo[23];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i += 2) {
    uint16_t temp1 = left[i * 2 + 3];
    uint16_t temp2 = left[i * 2 + 2];
    uint16_t temp3 = left[i * 2 + 1];
    uint16_t temp4 = left[i * 2 + 4];
    vo[i]     = (temp1 + temp2 * 2 + temp3 + 2) >> 2;
    ve[i]     = (temp4 + temp1 * 2 + temp2 + 2) >> 2;
    if (i + 1 < 8 - 1) {
        vo[i+1] = (left[(i+1) * 2 + 3] + left[(i+1) * 2 + 2] * 2 + left[(i+1) * 2 + 1] + 2) >> 2;
        ve[i+1] = (left[(i+1) * 2 + 4] + left[(i+1) * 2 + 3] * 2 + left[(i+1) * 2 + 2] + 2) >> 2;
    }
}
}
