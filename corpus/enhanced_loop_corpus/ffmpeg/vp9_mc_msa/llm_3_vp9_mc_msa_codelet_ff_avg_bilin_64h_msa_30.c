#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern  uint8_t *src;
extern ptrdiff_t src_stride;
extern int height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
ptrdiff_t i;
uint8_t *src_ptr = src;
uint8_t *dst_ptr = dst;
for (loop_cnt = height; loop_cnt--;) {
    for (i = 0; i < 8; i += 2) {
        dst_ptr[i] = src_ptr[i + 1];
        dst_ptr[i + 1] = src_ptr[i];
    }
    src_ptr += src_stride;
    dst_ptr += dst_stride;
}
}
