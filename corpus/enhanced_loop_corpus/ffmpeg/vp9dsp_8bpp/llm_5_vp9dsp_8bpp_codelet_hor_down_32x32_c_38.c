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
    for (i = 0; i < 32 - 2; i++) {
        uint8_t temp_left = left[i + 1];
        v[i * 2] = (temp_left + left[i] + 1) >> 1;

        if (left[i + 2] > left[i]) {
            v[i * 2 + 1] = (left[i + 2] + temp_left * 2 + left[i] + 2) >> 2;
        } else {
            v[i * 2 + 1] = (left[i] + temp_left * 2 + left[i + 2] + 2) >> 2;
        }

        if (i == 0) {
            v[32 * 2 + i] = (top[i] * 4 + 2) >> 2;
        } else {
            v[32 * 2 + i] = (top[i - 1] + top[i] * 2 + top[i + 1] + 2) >> 2;
        }
    }
}
