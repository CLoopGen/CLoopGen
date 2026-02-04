#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 1); loop_cnt--;) {
        // Variant 2: Strided memory access with increasing stride over iterations
        int32_t eff_src_stride = src_stride + (loop_cnt & 0x3) * 2;
        int32_t eff_dst_stride = dst_stride + (loop_cnt & 0x3) * 2;

        uint8_t *s = src;
        uint8_t *d = dst;

        // Access every 4th byte in a strided pattern
        for (int i = 0; i < 16; i += 4) {
            d[i] = s[i];
        }

        src += eff_src_stride;
        dst += eff_dst_stride;
    }
}
