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
extern  uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t *index_map = (ptrdiff_t*)alloca((h + 5) * sizeof(ptrdiff_t));
    for (int idx = 0; idx < h + 5; idx++) {
        index_map[idx] = idx * (ptrdiff_t)srcStride;
    }
    for (i = 0; i < h + 5; i++) {
        ptrdiff_t src_idx = index_map[i];
        ptrdiff_t tmp_idx = i * (ptrdiff_t)tmpStride;
        tmp[tmp_idx] = (src[src_idx] + src[src_idx + 1]) * 20 
                     - (src[src_idx - 1] + src[src_idx + 2]) * 5 
                     + (src[src_idx - 2] + src[src_idx + 3]) + pad;
        tmp[tmp_idx + 1] = (src[src_idx + 1] + src[src_idx + 2]) * 20 
                         - (src[src_idx] + src[src_idx + 3]) * 5 
                         + (src[src_idx - 1] + src[src_idx + 4]) + pad;
    }
}
