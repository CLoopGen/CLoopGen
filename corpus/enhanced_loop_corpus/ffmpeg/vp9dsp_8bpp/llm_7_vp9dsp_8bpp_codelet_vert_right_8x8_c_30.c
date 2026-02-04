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
uint8_t prev_left_val = left[0];
for (i = 0; i < 8 / 2 - 2; i++) {
    int idx1 = i * 2 + 1;
    int idx2 = i * 2 + 2;
    int idx3 = i * 2 + 3;
    int idx4 = i * 2 + 4;

    uint8_t current_avg = (left[idx3] + left[idx2] * 2 + prev_left_val + 2) >> 2;
    vo[i] = current_avg;

    ve[i] = (left[idx4] + left[idx3] * 2 + left[idx2] + 2) >> 2;

    prev_left_val = left[idx1];
}
}
