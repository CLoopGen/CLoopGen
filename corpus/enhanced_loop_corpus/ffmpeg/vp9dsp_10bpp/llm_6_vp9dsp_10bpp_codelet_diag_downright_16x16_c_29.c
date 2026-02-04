#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *top;
extern  uint16_t *left;
extern int i;
extern uint16_t v[31];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t temp_left[15], temp_top[15];
    for (i = 0; i < 16 - 2; i++) {
        temp_left[i] = (left[i] + left[i + 1] * 2 + left[i + 2] + 2) >> 2;
        temp_top[i] = (top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2;
    }
    for (i = 0; i < 16 - 2; i++) {
        v[i] = temp_left[i];
        v[16 + 1 + i] = temp_top[i];
    }
}
