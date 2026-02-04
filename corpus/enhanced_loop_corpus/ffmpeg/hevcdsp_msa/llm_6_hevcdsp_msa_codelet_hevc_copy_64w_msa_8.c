#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int16_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_accum = 0;
    for (loop_cnt = (height >> 1); loop_cnt--;) {
        temp_accum += src[0]; 
        dst[0] = (int16_t)(src[0] + temp_accum);
        {
        }
        ;
        {
        }
        ;
        src += src_stride;
        temp_accum += src[0];
        dst[1] = (int16_t)(src[0] + temp_accum);
        {
        }
        ;
        {
        }
        ;
        src += src_stride;
        {
        }
        ;
        {
        }
        ;
        {
        }
        ;
        {
        }
        ;
        {
            dst[2] = (int16_t)(temp_accum >> 1);
        }
        ;
        {
            dst[3] = (int16_t)(temp_accum >> 2);
        }
        ;
        dst += dst_stride;
        {
        }
        ;
        {
        }
        ;
        {
        }
        ;
        {
        }
        ;
        {
            dst[2] = (int16_t)(temp_accum - 100);
        }
        ;
        {
            dst[3] = (int16_t)(temp_accum - 200);
        }
        ;
        dst += dst_stride;
    }
}
