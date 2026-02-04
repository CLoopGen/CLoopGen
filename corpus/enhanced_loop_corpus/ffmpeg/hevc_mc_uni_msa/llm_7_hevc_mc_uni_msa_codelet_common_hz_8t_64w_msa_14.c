#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint8_t *local_src = src;
uint8_t *local_dst = dst;
int32_t local_height = height;

for (loop_cnt = 0; loop_cnt < local_height; ++loop_cnt) {
    for (int offset = 0; offset < 8; ++offset) {
        local_dst[offset] = local_src[offset];
    }
    
    for (int offset = 8; offset < 16; ++offset) {
        local_dst[offset] = local_src[offset] ^ 0xFF;
    }
    
    local_src += src_stride;
    local_dst += dst_stride;
}

src = local_src;
dst = local_dst;
}
