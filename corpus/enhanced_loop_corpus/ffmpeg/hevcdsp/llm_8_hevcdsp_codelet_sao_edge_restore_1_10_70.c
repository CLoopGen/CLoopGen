#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride_dst;
extern ptrdiff_t stride_src;
extern int y;
extern uint16_t *dst;
extern uint16_t *src;
extern int init_y;
extern int height;
extern int save_upper_left;
extern int save_lower_left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int start_y = init_y + save_upper_left;
    int end_y = height - save_lower_left;
    ptrdiff_t scaled_stride_dst = stride_dst * sizeof(uint16_t);
    ptrdiff_t scaled_stride_src = stride_src * sizeof(uint16_t);
    uint16_t *dst_ptr = (uint16_t*)((char*)dst + start_y * scaled_stride_dst);
    uint16_t *src_ptr = (uint16_t*)((char*)src + start_y * scaled_stride_src);
    
    for (int i = 0; i < end_y - start_y; i++) {
        dst_ptr[i * (scaled_stride_dst / sizeof(uint16_t))] = src_ptr[i * (scaled_stride_src / sizeof(uint16_t))];
    }
}
