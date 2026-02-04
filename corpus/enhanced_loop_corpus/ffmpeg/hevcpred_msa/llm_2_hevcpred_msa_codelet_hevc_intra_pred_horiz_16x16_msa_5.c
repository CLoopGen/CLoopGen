#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src_left;
extern int32_t stride;
extern uint8_t *tmp_dst;
extern uint32_t row;
extern uint8_t inp0;
extern uint8_t inp1;
extern uint8_t inp2;
extern uint8_t inp3;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (row = 4; row--;) {
        inp0 = src_left[0 * stride];
        inp1 = src_left[1 * stride];
        inp2 = src_left[2 * stride];
        inp3 = src_left[3 * stride];
        src_left += (4 * stride);
        tmp_dst += (4 * stride);
    }
}
