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
    uint8_t local_inp0 = inp0;
    uint8_t local_inp1 = inp1;
    uint8_t local_inp2 = inp2;
    uint8_t local_inp3 = inp3;
    for (row = 0; row < 8; row++) {
        local_inp3 = local_inp2;
        local_inp2 = local_inp1;
        local_inp1 = local_inp0;
        local_inp0 = src_left[row * 4];

        inp0 = local_inp0;
        inp1 = local_inp1;
        inp2 = local_inp2;
        inp3 = local_inp3;

        *(dst) = local_inp0;
        dst += stride;
        *(dst) = local_inp1;
        dst += stride;
        *(dst) = local_inp2;
        dst += stride;
        *(dst) = local_inp3;
        dst += stride;
    }
}
