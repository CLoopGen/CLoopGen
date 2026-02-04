#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src_left;
extern uint8_t *dst;
extern int32_t stride;
extern uint32_t row;
extern uint8_t inp0;
extern uint8_t inp1;
extern uint8_t inp2;
extern uint8_t inp3;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp[4];
    for (row = 0; row < 8; row++) {
        temp[0] = src_left[row * 4];
        temp[1] = src_left[row * 4 + 1];
        temp[2] = src_left[row * 4 + 2];
        temp[3] = src_left[row * 4 + 3];

        inp0 = temp[0];
        inp1 = temp[1]; 
        inp2 = temp[2];
        inp3 = temp[3];

        dst += stride;
        dst += stride;
        dst += stride;
        dst += stride;
    }
}
