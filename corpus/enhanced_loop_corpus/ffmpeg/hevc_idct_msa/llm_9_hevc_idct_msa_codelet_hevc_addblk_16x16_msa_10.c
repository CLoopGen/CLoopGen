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
    for (loop_cnt = 2; loop_cnt--;) {
        uint8_t block[16];
        int coeff_idx = 0;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int val = coeffs[coeff_idx++] + 128;
                val = (val < 0) ? 0 : (val > 255) ? 255 : val;
                block[i * 4 + j] = (uint8_t)val;
            }
        }

        for (int i = 0; i < 4; i++) {
            temp_dst[i * stride + 0] = block[i * 4 + 0];
            temp_dst[i * stride + 1] = block[i * 4 + 1];
            temp_dst[i * stride + 2] = block[i * 4 + 2];
            temp_dst[i * stride + 3] = block[i * 4 + 3];
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                dst[i * stride + j] += temp_dst[i * stride + j];
            }
        }

        temp_dst += (4 * stride);
        coeffs += 64;
        dst += (4 * stride);
    }
}
