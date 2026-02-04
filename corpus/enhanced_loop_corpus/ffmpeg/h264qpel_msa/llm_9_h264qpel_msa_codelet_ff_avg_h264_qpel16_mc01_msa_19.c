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
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int idx = i * 4 + j;
                dst[i * stride + j] = src[j * stride + i] ^ 0xFF;
            }
        }
        
        src += (8 * stride);
        dst += (8 * stride);
        
        for (int k = 0; k < 3; k++) {
            dst[k * stride] = src[(k+1) * stride] + k;
        }
    }
}
