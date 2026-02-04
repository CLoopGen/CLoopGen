#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *left;
extern int i;
extern uint16_t v[30];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t temp_sum;
    for (i = 0; i < 16 - 2; i++) {
        temp_sum = left[i] + left[i + 1];
        v[i * 2] = (temp_sum + 1) >> 1;
        v[i * 2 + 1] = (temp_sum + left[i + 1] + left[i + 2] + 2) >> 2;
    }
}
