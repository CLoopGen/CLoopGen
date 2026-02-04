#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *left;
extern int i;
extern uint8_t ve[23];
extern uint8_t vo[23];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 16 / 2 - 2; i++) {
        vo[i] = (left[i * 2 + 3] + left[i * 2 + 2] * 2 + left[i * 2 + 1] + 2) >> 2;
        ve[i - 1] = (left[i * 2 + 2] + left[i * 2 + 1] * 2 + left[i * 2] + 2) >> 2;
    }
    if (16 / 2 - 2 > 0) {
        ve[16 / 2 - 3] = (left[16 - 2] + left[16 - 3] * 2 + left[16 - 4] + 2) >> 2;
    }
}
