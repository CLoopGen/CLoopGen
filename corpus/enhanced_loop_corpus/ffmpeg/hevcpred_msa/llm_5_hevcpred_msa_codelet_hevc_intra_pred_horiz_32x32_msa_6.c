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
    for (row = 0; row < 8; row++) {
        inp0 = src_left[row * 4];
        dst += stride;
        if (row < 6) {
            inp1 = src_left[row * 4 + 1];
            dst += stride;
        } else {
            inp1 = inp0;
            dst += stride;
        }
        inp2 = src_left[row * 4 + 2];
        dst += stride;
        if (row != 7) {
            inp3 = src_left[row * 4 + 3];
        } else {
            inp3 = inp2;
        }
        dst += stride;
    }
}
