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
    for (loop_cnt = 6; loop_cnt--;) {
        int16_t sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
        for (int i = 0; i < 16; i++) {
            sum1 += coeffs[i + 0];
            sum2 += coeffs[i + 16];
            sum3 += coeffs[i + 32];
            sum4 += coeffs[i + 48];
        }
        temp_dst[0] = (uint8_t)((sum1 >> 4) & 0xFF);
        temp_dst[stride] = (uint8_t)((sum2 >> 4) & 0xFF);
        temp_dst[2*stride] = (uint8_t)((sum3 >> 4) & 0xFF);
        temp_dst[3*stride] = (uint8_t)((sum4 >> 4) & 0xFF);

        for (int i = 0; i < 4; i++) {
            dst[i * stride] = temp_dst[i * stride] ^ 0x80;
        }

        temp_dst += (4 * stride);
        coeffs += 64;
        dst += (4 * stride);
    }
}
