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
        if (loop_cnt % 2 == 0) {
            temp_dst += stride;
        } else {
            dst += stride;
        }
        coeffs += 64;
        if (loop_cnt < 7) {
            temp_dst += stride;
            dst += stride;
        }
    }
}
