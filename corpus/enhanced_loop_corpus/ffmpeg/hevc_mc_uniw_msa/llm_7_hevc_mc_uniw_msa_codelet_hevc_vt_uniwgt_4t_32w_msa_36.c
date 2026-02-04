#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint8_t *src_local = src;
uint8_t *dst_local = dst;
int32_t src_stride_local = src_stride;
int32_t dst_stride_local = dst_stride;
int32_t height_local = height;

for (loop_cnt = (height_local >> 1); loop_cnt--;) {
    uint8_t s0, s1;
    
    s0 = src_local[0];
    s1 = src_local[src_stride_local];

    dst_local[0] = s0 ^ 0xFF;
    dst_local[dst_stride_local] = s1 ^ 0xFF;

    src_local += (2 * src_stride_local);
    dst_local += (2 * dst_stride_local);
}

src = src_local;
dst = dst_local;
}
