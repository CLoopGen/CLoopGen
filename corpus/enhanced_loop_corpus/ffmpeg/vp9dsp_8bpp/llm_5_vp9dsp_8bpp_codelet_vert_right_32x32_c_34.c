#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *left;
extern int i;
extern uint8_t ve[47];
extern uint8_t vo[47];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32 / 2 - 2; i++) {
        uint8_t temp_sum_odd = left[i * 2 + 3] + left[i * 2 + 2] * 2 + left[i * 2 + 1];
        uint8_t temp_sum_even = left[i * 2 + 4] + left[i * 2 + 3] * 2 + left[i * 2 + 2];

        if (temp_sum_odd > 10 && temp_sum_even > 10) {
            vo[i] = (temp_sum_odd + 2) >> 2;
            ve[i] = (temp_sum_even + 2) >> 2;
        } else {
            vo[i] = left[i * 2 + 2];
            ve[i] = left[i * 2 + 3];
        }
    }
}
