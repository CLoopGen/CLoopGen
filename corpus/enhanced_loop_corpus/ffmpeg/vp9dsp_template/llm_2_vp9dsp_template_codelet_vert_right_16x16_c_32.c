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
for (i = 0; i < 16 / 2 - 2; i++) {
    int idx = i * 2;
    vo[i] = (left[idx + 3] + left[idx + 2] * 2 + left[idx + 1] + 2) >> 2;
    ve[i] = (left[idx + 4] + left[idx + 3] * 2 + left[idx + 2] + 2) >> 2;
}
}
