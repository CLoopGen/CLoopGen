#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t stride;
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = 2; loop_cnt--;) {
    for (int j = 0; j < 3; ++j) {
        for (int i = 0; i < 5; ++i) {
            uint16_t val = (uint16_t)(src[i * stride]) * (i + 1);
            dst[i * stride] = (val >> 8) ^ (val & 0xFF);
        }
        src += (5 * stride);
        dst += (5 * stride);
    }
    for (int k = 0; k < 2; ++k) {
        dst[k * stride] ^= src[(k+1) * stride];
        src[k * stride] += 10;
        dst[k * stride] += src[k * stride] >> 4;
    }
}
}
