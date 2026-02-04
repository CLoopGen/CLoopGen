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
    ptrdiff_t i, j;
    uint8_t **src_ptrs = (uint8_t**)alloca(height * sizeof(uint8_t*));
    uint8_t **dst_ptrs = (uint8_t**)alloca(height * sizeof(uint8_t*));
    
    for (i = 0; i < height; i++) {
        src_ptrs[i] = src + i * src_stride;
        dst_ptrs[i] = dst + i * dst_stride;
    }

    for (loop_cnt = (height >> 2); loop_cnt--;) {
        i = (height - (loop_cnt + 1) * 4);
        for (j = 0; j < 4; j++) {
            uint8_t *s = src_ptrs[i + j];
            uint8_t *d = dst_ptrs[i + j];
            for (int k = 0; k < 4; k++) {
                d[k] = s[k];
            }
        }
    }
}
