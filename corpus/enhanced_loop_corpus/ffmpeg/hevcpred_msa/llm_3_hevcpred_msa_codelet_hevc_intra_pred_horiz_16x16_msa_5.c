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
    uint8_t *access_ptr = src_left;
    for (row = 4; row--;) {
        inp0 = access_ptr[0];
        inp1 = access_ptr[1];
        inp2 = access_ptr[2];
        inp3 = access_ptr[3];
        access_ptr += 4;
        tmp_dst += (4 * stride);
    }
    src_left = access_ptr;
}
