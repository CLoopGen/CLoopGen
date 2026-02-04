#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern  uint8_t *left;
extern int i;
extern uint8_t v[63];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i++) {
    uint8_t avg_left = (left[i] + left[i + 2] + 1) >> 1;
    uint8_t smooth_left = (avg_left + left[i + 1] + 1) >> 1;
    v[i] = smooth_left;
    uint8_t avg_top = (top[i] + top[i + 2] + 1) >> 1;
    uint8_t smooth_top = (avg_top + top[i + 1] + 1) >> 1;
    v[32 + 1 + i] = smooth_top;
}
}
