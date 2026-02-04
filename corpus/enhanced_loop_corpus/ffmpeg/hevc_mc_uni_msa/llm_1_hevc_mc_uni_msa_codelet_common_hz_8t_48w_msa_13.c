#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = 8; loop_cnt--; ) {
        for (int outer_inner = 2; outer_inner--; ) {
            for (int middle_inner = 2; middle_inner--; ) {
                for (int inner_most = 2; inner_most--; ) {
                    src += src_stride;
                    dst += dst_stride;
                }
            }
        }
    }
}
