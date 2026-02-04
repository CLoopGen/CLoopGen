#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *left;
extern int i;
extern uint8_t v[62];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t prev_temp = 0;
    for (i = 0; i < 32 - 2; i++) {
        uint8_t curr = (left[i] + left[i + 1] + 1 + prev_temp) >> 1;
        v[i * 2] = curr;
        v[i * 2 + 1] = (left[i] + left[i + 1] * 2 + left[i + 2] + 2) >> 2;
        prev_temp = curr;
    }
}
