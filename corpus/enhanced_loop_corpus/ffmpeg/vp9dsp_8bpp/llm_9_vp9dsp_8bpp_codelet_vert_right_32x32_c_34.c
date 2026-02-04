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
for (i = 0; i < 48; i += 3) {
    uint8_t temp1 = (left[i + 2] + left[i + 1] * 3 + left[i] + left[i + 3] + 3) >> 3;
    uint8_t temp2 = (left[i + 3] + left[i + 2] * 3 + left[i + 1] + left[i + 4] + 3) >> 3;
    if (i / 3 < 47) {
        vo[i / 3] = temp1;
        ve[i / 3] = temp2;
    }
}
}
