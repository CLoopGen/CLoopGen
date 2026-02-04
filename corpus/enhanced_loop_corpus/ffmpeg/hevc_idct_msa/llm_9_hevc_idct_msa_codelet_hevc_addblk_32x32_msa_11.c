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
    for (loop_cnt = 7; loop_cnt--;) {
        uint8_t val1, val2;
        int32_t offset = 0;
        
        for (int i = 0; i < 4; i++) {
            val1 = (coeffs[i] + coeffs[i + 64]) & 0xFF;
            val2 = (coeffs[i + 32] ^ coeffs[i + 96]) & 0x7F;
            temp_dst[offset] = val1;
            dst[offset] = val2;
            offset += stride;
        }

        for (int j = 0; j < 2; j++) {
            temp_dst[offset] = coeffs[127 - j];
            dst[offset] = coeffs[j] & 0xFF;
            offset += stride;
        }

        coeffs += 128;
        temp_dst += 2 * stride;
        dst += 2 * stride;
    }
}
