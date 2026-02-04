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
    for (loop_cnt = 28; loop_cnt--;) {
        int16_t sum = 0;
        for (int i = 0; i < 8; i++) {
            sum += coeffs[i] * 2;
        }
        dst[0] = (sum >> 4) & 0xFF;
        temp_dst[0] = (sum + 128) >> 8;
        temp_dst += stride;
        dst += stride;
        coeffs += 8;
    }
}
