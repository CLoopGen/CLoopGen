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
    uint8_t current_offset = i * 2 + 2;
    uint8_t adjusted = (prev_left_val + left[current_offset]) >> 1;
    vo[i] = (adjusted + left[current_offset + 1] * 2 + left[current_offset - 1] + 2) >> 2;
    ve[i] = (left[current_offset + 2] + adjusted * 2 + left[current_offset] + 2) >> 2;
    prev_left_val = left[current_offset + 1]; 
}
}
