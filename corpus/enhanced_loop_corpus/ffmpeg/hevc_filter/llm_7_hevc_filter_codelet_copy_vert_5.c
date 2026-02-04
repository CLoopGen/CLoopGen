#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int height;
extern ptrdiff_t stride_dst;
extern ptrdiff_t stride_src;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t *prev_dst_val_ptr = NULL;
    uint16_t prev_dst_val = 0;
    for (i = 0; i < height; i++) {
        uint16_t curr_src_val = *(uint16_t *)src;
        uint16_t *d = (uint16_t *)dst;
        if (prev_dst_val_ptr) {
            *d = curr_src_val + prev_dst_val;
        } else {
            *d = curr_src_val;
        }
        prev_dst_val_ptr = d;
        prev_dst_val = *d;
        dst += stride_dst;
        src += stride_src;
    }
}
