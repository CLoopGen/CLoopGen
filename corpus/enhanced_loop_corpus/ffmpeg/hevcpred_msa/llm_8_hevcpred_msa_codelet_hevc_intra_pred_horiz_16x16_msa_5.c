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
for (row = 8; row--;) {
    inp0 = src_left[0];
    inp1 = src_left[1];
    inp2 = src_left[2];
    inp3 = src_left[3];
    src_left += 4;
    
    inp0 ^= inp1;
    inp2 ^= inp3;
    inp0 += inp2;
    
    tmp_dst[0] = inp0;
    tmp_dst[1] = inp1;
    tmp_dst[2] = inp2;
    tmp_dst[3] = inp3;
    
    tmp_dst += stride;
}
}
