#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern  uint8_t *left;
extern int i;
extern uint8_t v[15];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp_left[6], temp_top[6];
    for (i = 0; i < 8 - 2; i++) {
        temp_left[i] = (left[i] + left[i + 1] * 2 + left[i + 2] + 2) >> 2;
        temp_top[i] = (top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2;
    }
    for (i = 0; i < 8 - 2; i++) {
        v[i] = temp_left[i];
        v[8 + 1 + i] = temp_top[i];
    }
}
