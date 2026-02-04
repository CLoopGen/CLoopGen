#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *tmp;
extern int tmpStride;
extern int srcStride;
extern  int h;
extern  int pad;
extern int i;
extern  uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
ptrdiff_t *index_map = (ptrdiff_t*)alloca((h + 5) * sizeof(ptrdiff_t));
for (int idx = 0; idx < h + 5; idx++) {
    index_map[idx] = idx * srcStride;
}
for (i = 0; i < h + 5; i++) {
    ptrdiff_t src_idx = index_map[i];
    tmp[0] = (src[src_idx] + src[src_idx + 1]) * 20 - (src[src_idx - 1] + src[src_idx + 2]) * 5 + (src[src_idx - 2] + src[src_idx + 3]) + pad;
    tmp[1] = (src[src_idx + 1] + src[src_idx + 2]) * 20 - (src[src_idx] + src[src_idx + 3]) * 5 + (src[src_idx - 1] + src[src_idx + 4]) + pad;
    tmp[2] = (src[src_idx + 2] + src[src_idx + 3]) * 20 - (src[src_idx + 1] + src[src_idx + 4]) * 5 + (src[src_idx] + src[src_idx + 5]) + pad;
    tmp[3] = (src[src_idx + 3] + src[src_idx + 4]) * 20 - (src[src_idx + 2] + src[src_idx + 5]) * 5 + (src[src_idx + 1] + src[src_idx + 6]) + pad;
    tmp += tmpStride;
}
}
