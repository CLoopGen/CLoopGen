#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *left;
extern int i;
extern uint8_t v[62];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint8_t prev_left_val = 0;
for (i = 0; i < 32 - 2; i++) {
    uint8_t current = left[i];
    v[i * 2] = (prev_left_val + current + 1) >> 1;
    v[i * 2 + 1] = (prev_left_val + (current << 1) + left[i + 1] + 2) >> 2;
    prev_left_val = current;
}
}
