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
    uint8_t *src_base = src_left;
    for (row = 0; row < 32; row += 4) {
        inp0 = *(src_base++);
        inp1 = *(src_base++);
        inp2 = *(src_base++);
        inp3 = *(src_base++);
        dst += stride * 4;
    }
}
