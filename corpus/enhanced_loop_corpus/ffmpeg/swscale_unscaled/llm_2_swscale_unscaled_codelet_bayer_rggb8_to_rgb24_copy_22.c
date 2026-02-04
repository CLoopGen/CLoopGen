#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int src_stride;
extern uint8_t *dst;
extern int dst_stride;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < width; i += 2) {
    int dst_idx_base = i * dst_stride;
    uint8_t *src_ptr = &src[i * src_stride];
    
    dst[dst_idx_base + 2] = dst[dst_idx_base + 3 + 2] = dst[dst_idx_base + dst_stride + 3 + 2] = dst[dst_idx_base + dst_stride + 2] = src_ptr[1] >> 0;
    dst[dst_idx_base + 3 + 1] = src_ptr[1] >> 0;
    dst[dst_idx_base + 1] = dst[dst_idx_base + dst_stride + 3 + 1] = ((unsigned int)src_ptr[1] + (unsigned int)src_ptr[src_stride]) >> 1;
    dst[dst_idx_base + dst_stride + 1] = src_ptr[src_stride] >> 0;
    dst[dst_idx_base + dst_stride] = dst[dst_idx_base] = dst[dst_idx_base + 3] = dst[dst_idx_base + dst_stride] = src_ptr[0] >> 0;

    src += 2 * src_stride;
    dst += 6;
}
}
