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
    for (loop_cnt = 2; loop_cnt--; ) {
        for (int j = 0; j < 2; ++j) {
            {
            }
            ;
            {
            }
            ;
        }
        src_tmp += (4 * src_stride);
        for (int j = 0; j < 2; ++j) {
            {
            }
            ;
            {
            }
            ;
        }
        dst_tmp += (4 * dst_stride);
    }
}
