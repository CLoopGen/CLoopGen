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
uint8_t prev_left_val = left[0];
for (i = 0; i < 32 / 2 - 2; i++) {
    uint8_t current = left[i * 2 + 2];
    vo[i] = (prev_left_val + current * 2 + left[i * 2 + 1] + 2) >> 2;
    ve[i] = (left[i * 2 + 4] + left[i * 2 + 3] * 2 + current + 2) >> 2;
    prev_left_val = left[i * 2 + 3];
}
}
