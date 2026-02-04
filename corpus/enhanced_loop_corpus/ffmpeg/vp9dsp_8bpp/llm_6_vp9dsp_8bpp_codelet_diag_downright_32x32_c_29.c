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
for (i = 0; i < 32 - 2; i++) {
    uint8_t temp_left = (left[i] + left[i + 1] * 2 + left[i + 2] + 2) >> 2;
    uint8_t temp_top = (top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2;
    v[i] = temp_left;
    v[32 + 1 + i] = temp_top;
}
}
