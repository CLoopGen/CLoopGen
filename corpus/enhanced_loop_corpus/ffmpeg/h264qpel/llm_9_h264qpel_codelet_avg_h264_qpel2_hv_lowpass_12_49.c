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
for (i = 0; i < h + 3; i += 2) {
    tmp[0] = (src[0] + src[1]) * 25 - (src[-1] + src[2]) * 7 + (src[-2] + src[3]) * 2 - (src[-3] + src[4]) + pad;
    tmp[1] = (src[1] + src[2]) * 25 - (src[0] + src[3]) * 7 + (src[-1] + src[4]) * 2 - (src[-2] + src[5]) + pad;
    if (i + 1 < h + 3) {
        int32_t *tmp_next = (int32_t*)((char*)tmp + tmpStride);
        uint16_t *src_next = (uint16_t*)((char*)src + srcStride);
        tmp_next[0] = (src_next[0] + src_next[1]) * 25 - (src_next[-1] + src_next[2]) * 7 + (src_next[-2] + src_next[3]) * 2 - (src_next[-3] + src_next[4]) + pad;
        tmp_next[1] = (src_next[1] + src_next[2]) * 25 - (src_next[0] + src_next[3]) * 7 + (src_next[-1] + src_next[4]) * 2 - (src_next[-2] + src_next[5]) + pad;
    }
    tmp = (int32_t*)((char*)tmp + 2 * tmpStride);
    src = (uint16_t*)((char*)src + 2 * srcStride);
}
}
