#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern  uint8_t *left;
extern int i;
extern uint8_t v[46];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < 16 - 3; i++) {
    uint8_t avg1 = (left[i] + left[i + 1] + 1) >> 1;
    uint8_t avg2 = (left[i + 1] * 3 + left[i] + left[i + 2] + 3) >> 3;
    v[i * 2] = avg1;
    v[i * 2 + 1] = avg2;
    uint8_t smooth_top = (top[i] * 3 + top[i - 1] + top[i + 1] + 2) >> 3;
    v[32 + i] = smooth_top;
}
}
