#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t src_stride;
extern int32_t dst_stride;
extern uint32_t loop_cnt;
extern uint8_t *src_tmp;
extern int16_t *dst_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = 4; loop_cnt--; ) {
        for (int i = 0; i < 4; ++i) {
            src_tmp += src_stride;
            dst_tmp += dst_stride;
        }
        src_tmp += 3 * src_stride; 
        dst_tmp += 3 * dst_stride;
    }
}
