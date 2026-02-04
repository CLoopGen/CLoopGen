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
    for (i = 0; i < 16 - 2; i++) {
        uint16_t temp_left = left[i] + left[i + 1] * 2 + left[i + 2];
        uint16_t temp_top = top[i] + top[i + 1] * 2 + top[i + 2];

        if ((temp_left & 0x3) >= 2) {
            v[i] = (temp_left + 2) >> 2;
        } else {
            v[i] = temp_left >> 2;
        }

        if ((temp_top & 0x3) >= 2 && i > 0) {
            v[16 + 1 + i] = (temp_top + 2) >> 2;
        } else {
            v[16 + 1 + i] = (temp_top + 1) >> 2;
        }
    }
}
