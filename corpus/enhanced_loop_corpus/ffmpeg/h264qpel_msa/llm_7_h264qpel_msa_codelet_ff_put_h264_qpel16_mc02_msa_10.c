#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t stride;
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint8_t local_buf[16];
ptrdiff_t idx = 0;
for (loop_cnt = 4; loop_cnt--;) {
    local_buf[idx + 0]  = src[0];
    local_buf[idx + 1]  = src[stride];
    local_buf[idx + 2]  = src[2*stride];
    local_buf[idx + 3]  = src[3*stride];
    
    idx += 4;
    
    if (idx == 16) {
        for (int i = 0; i < 16; i++) {
            dst[i * stride] = local_buf[i] + 1;
        }
        idx = 0;
    }
    
    src += (4 * stride);
}
if (idx > 0) {
    for (int i = 0; i < idx; i++) {
        dst[i * stride] = local_buf[i] + 1;
    }
}
dst += (4 * stride);
}
