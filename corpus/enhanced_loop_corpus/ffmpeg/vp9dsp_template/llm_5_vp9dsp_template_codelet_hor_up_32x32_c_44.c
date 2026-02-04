#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *left;
extern int i;
extern uint8_t v[62];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32 - 2; i++) {
        uint8_t temp_sum = left[i] + left[i + 1];
        if (temp_sum > 128) {
            v[i * 2] = temp_sum >> 1;
        } else {
            v[i * 2] = (temp_sum + 1) >> 1;
        }
        int extended_sum = left[i] + left[i + 1] * 2 + left[i + 2];
        v[i * 2 + 1] = (extended_sum + 2) >> 2;
    }
}
