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
    for (i = 0; i < 8 - 2; i++) {
        uint8_t temp_left = left[i + 1];
        uint8_t temp_top = top[i + 1];
        v[i] = (temp_left == 0) ? 
               ((left[i] + left[i + 2] + 1) >> 1) : 
               (left[i] + temp_left * 2 + left[i + 2] + 2) >> 2;

        v[8 + 1 + i] = (temp_top > 127) ? 
                       top[i + 1] : 
                       (top[i] + temp_top * 2 + top[i + 2] + 2) >> 2;
    }
}
