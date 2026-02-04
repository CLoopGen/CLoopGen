#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern  uint8_t *left;
extern int i;
extern uint8_t v[94];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint8_t prev_top_val = (top[-1] + top[0] * 2 + top[1] + 2) >> 2;
for (i = 0; i < 32 - 2; i++) {
    v[i * 2] = (left[i + 1] + left[i + 0] + 1) >> 1;
    v[i * 2 + 1] = (left[i + 2] + left[i + 1] * 2 + left[i + 0] + 2) >> 2;
    uint8_t curr_top_val = (top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2;
    v[32 * 2 + i] = prev_top_val;
    prev_top_val = curr_top_val;
}
v[32 * 2 + 32 - 2 - 1] = prev_top_val; // Store final computed value
}
