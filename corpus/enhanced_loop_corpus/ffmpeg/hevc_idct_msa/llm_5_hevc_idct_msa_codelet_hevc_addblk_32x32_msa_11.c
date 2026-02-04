#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coeffs;
extern uint8_t *dst;
extern int32_t stride;
extern uint8_t loop_cnt;
extern uint8_t *temp_dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = 14; loop_cnt--;) {
        {
            dst += stride;
        }
        if (loop_cnt > 10) {
            temp_dst += stride;
        } else if (loop_cnt > 5) {
            temp_dst += stride * 2;
            coeffs += 32;
        } else {
            temp_dst += stride;
            coeffs += 64;
        }
        {
            {
                coeffs += 32;
            }
        }
        if ((loop_cnt & 1) == 0) {
            dst += stride;
        }
    }
}
