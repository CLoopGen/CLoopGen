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
for (i = 0; i < 16 / 2 - 1; i++) {
    vo[i] = (left[i * 2 + 3] + left[i * 2 + 2] * 3 + left[i * 2 + 1] + 1) >> 2;
    ve[i] = (left[i * 2 + 4] + left[i * 2 + 3] * 3 + left[i * 2 + 2] + 1) >> 2;
}
}
