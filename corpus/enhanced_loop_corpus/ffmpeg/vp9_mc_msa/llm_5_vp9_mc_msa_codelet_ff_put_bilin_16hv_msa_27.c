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
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        uint8_t *temp_src = src;
        ptrdiff_t offset = 0;
        
        if (temp_src != NULL) {
            offset = 4 * src_stride;
        }
        
        src += offset;
        
        dst += dst_stride;
        if (loop_cnt % 2 == 0) {
            dst += dst_stride;
        } else {
            dst += (2 * dst_stride);
        }
        dst += dst_stride;
    }
}
