#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern  uint8_t *left;
extern int i;
extern uint8_t v[31];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t prev_v0 = 0, prev_v17 = 0;
    for (i = 0; i < 16 - 2; i++) {
        uint8_t new_left_val = (left[i] + left[i + 1] * 2 + left[i + 2] + 2) >> 2;
        uint8_t new_top_val = (top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2;
        v[i] = (prev_v0 + new_left_val) >> 1;
        v[16 + 1 + i] = (prev_v17 + new_top_val) >> 1;
        prev_v0 = v[i];
        prev_v17 = v[16 + 1 + i];
    }
}
