#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t width;
extern uint8_t *src_tmp;
extern uint8_t *dst_tmp;
extern uint32_t loop_cnt;
extern uint32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (width >> 4); cnt--;) {
    src_tmp = src;
    dst_tmp = dst;
    uint8_t prev_src = 0;
    uint8_t accumulated = 0;
    {
        for (int i = 0; i < 7; ++i) {
            uint8_t current = src_tmp[i * src_stride];
            accumulated ^= current; 
            dst_tmp[i * dst_stride] = accumulated;
            prev_src = current;
        }
    }
    ;
    {
        uint8_t feedback = dst_tmp[6 * dst_stride];
        src_tmp += (7 * src_stride);
        dst_tmp[7 * dst_stride] = feedback ^ src_tmp[0];
    }
    ;
    {
        accumulated = dst_tmp[7 * dst_stride];
    }
    ;
    {
        dst_tmp[8 * dst_stride] = accumulated;
    }
    ;
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        {
            uint8_t val = src_tmp[0] ^ accumulated;
            dst_tmp[0] = val;
            accumulated = val;
        }
        ;
        {
            uint8_t val = src_tmp[src_stride] ^ dst_tmp[0];
            dst_tmp[dst_stride] = val;
            accumulated ^= val;
        }
        ;
        src_tmp += (4 * src_stride);
        {
            uint8_t val = src_tmp[0] + accumulated;
            dst_tmp[2 * dst_stride] = val;
            accumulated += val;
        }
        ;
        {
            uint8_t val = src_tmp[src_stride] + dst_tmp[2 * dst_stride];
            dst_tmp[3 * dst_stride] = val;
            accumulated += val;
        }
        ;
        {
            uint8_t val = src_tmp[2 * src_stride] ^ accumulated;
            dst_tmp[4 * dst_stride] = val;
            accumulated ^= val;
        }
        ;
        {
            uint8_t val = src_tmp[3 * src_stride] ^ dst_tmp[4 * dst_stride];
            dst_tmp[5 * dst_stride] = val;
            accumulated ^= val;
        }
        ;
        {
            uint8_t val = src_tmp[4 * src_stride] + accumulated;
            dst_tmp[6 * dst_stride] = val;
            accumulated += val;
        }
        ;
        {
            uint8_t val = src_tmp[5 * src_stride] + dst_tmp[6 * dst_stride];
            dst_tmp[7 * dst_stride] = val;
            accumulated += val;
        }
        ;
        {
            dst_tmp[8 * dst_stride] = accumulated;
        }
        ;
        {
            dst_tmp[9 * dst_stride] = accumulated ^ 0xFF;
        }
        ;
        dst_tmp += (4 * dst_stride);
    }
    src += 16;
    dst += 16;
}
}
