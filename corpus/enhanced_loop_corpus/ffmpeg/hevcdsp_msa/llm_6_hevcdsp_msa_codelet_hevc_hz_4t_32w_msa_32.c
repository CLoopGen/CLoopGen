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
    uint32_t temp_sum = 0;
    for (loop_cnt = height; loop_cnt--;) {
        temp_sum += src[0]; // Introduce RAW dependency: temp_sum used and updated
        src[1] = temp_sum;  // Introduce WAR/WAW: write after read/write on src
        src += src_stride;
        dst[0] = temp_sum;
        dst += dst_stride;
    }
}
