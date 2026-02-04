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
    int base = i + 1;
    vo[i] = (left[base] + left[base + 1] * 2 + left[base + 2] + 2) >> 2;
    ve[i] = (left[base + 1] + left[base + 2] * 2 + left[base + 3] + 2) >> 2;
}
}
