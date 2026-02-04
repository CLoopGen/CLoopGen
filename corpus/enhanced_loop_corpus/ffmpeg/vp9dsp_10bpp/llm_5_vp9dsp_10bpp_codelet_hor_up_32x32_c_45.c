#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *left;
extern int i;
extern uint16_t v[62];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32 - 2; i++) {
        uint16_t temp_sum = left[i] + left[i + 1];
        if (temp_sum > 100) {
            v[i * 2] = temp_sum >> 1;
        } else {
            continue;
        }
        v[i * 2 + 1] = (left[i] + left[i + 1] * 2 + left[i + 2] + 2) >> 2;
    }
}
