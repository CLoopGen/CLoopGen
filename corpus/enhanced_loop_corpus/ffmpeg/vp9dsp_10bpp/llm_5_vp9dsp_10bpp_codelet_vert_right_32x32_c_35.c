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
    for (i = 0; i < 32 / 2 - 2; i++) {
        int offset = i * 2;
        uint16_t temp1 = left[offset + 3] + (left[offset + 2] << 1) + left[offset + 1] + 2;
        uint16_t temp2 = left[offset + 4] + (left[offset + 3] << 1) + left[offset + 2] + 2;

        if (temp1 >= temp2) {
            vo[i] = temp1 >> 2;
            ve[i] = temp2 >> 2;
        } else {
            vo[i] = temp2 >> 2;
            ve[i] = temp1 >> 2;
        }
    }
}
