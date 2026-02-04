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
    uint8_t temp_buffer[4];
    for (row = 4; row--;) {
        temp_buffer[0] = src_left[0];
        temp_buffer[1] = src_left[1];
        temp_buffer[2] = src_left[2];
        temp_buffer[3] = src_left[3];
        src_left += 4;
        inp0 = temp_buffer[0] + 1;
        inp1 = temp_buffer[1] + inp0;
        inp2 = temp_buffer[2] + inp1;
        inp3 = temp_buffer[3] + inp2;
        tmp_dst[0] = inp3;
        tmp_dst[stride] = inp2;
        tmp_dst[2*stride] = inp1;
        tmp_dst[3*stride] = inp0;
        tmp_dst += (4 * stride);
    }
}
