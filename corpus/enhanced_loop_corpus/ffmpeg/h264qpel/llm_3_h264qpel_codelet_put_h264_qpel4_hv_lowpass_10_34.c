#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *tmp;
extern int tmpStride;
extern int srcStride;
extern  int h;
extern  int pad;
extern int i;
extern  uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h + 5; i++) {
    ptrdiff_t src_idx_base = i * srcStride;
    ptrdiff_t tmp_idx_base = i * tmpStride;
    tmp[tmp_idx_base + 0] = (src[src_idx_base + 0] + src[src_idx_base + 1]) * 20 - 
                            (src[src_idx_base - 1] + src[src_idx_base + 2]) * 5 + 
                            (src[src_idx_base - 2] + src[src_idx_base + 3]) + pad;
    tmp[tmp_idx_base + 1] = (src[src_idx_base + 1] + src[src_idx_base + 2]) * 20 - 
                            (src[src_idx_base + 0] + src[src_idx_base + 3]) * 5 + 
                            (src[src_idx_base - 1] + src[src_idx_base + 4]) + pad;
    tmp[tmp_idx_base + 2] = (src[src_idx_base + 2] + src[src_idx_base + 3]) * 20 - 
                            (src[src_idx_base + 1] + src[src_idx_base + 4]) * 5 + 
                            (src[src_idx_base + 0] + src[src_idx_base + 5]) + pad;
    tmp[tmp_idx_base + 3] = (src[src_idx_base + 3] + src[src_idx_base + 4]) * 20 - 
                            (src[src_idx_base + 2] + src[src_idx_base + 5]) * 5 + 
                            (src[src_idx_base + 1] + src[src_idx_base + 6]) + pad;
}
}
