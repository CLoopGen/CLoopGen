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
    for (row = 0; row < 4; row++) {
        for (int inner = 0; inner < 2; inner++) {
            uint32_t idx = (row * 2 + inner) * 4;
            inp0 = src_left[idx];
            inp1 = src_left[idx + 1];
            inp2 = src_left[idx + 2];
            inp3 = src_left[idx + 3];
            dst += stride;
            dst += stride;
            dst += stride;
            dst += stride;
        }
    }
}
