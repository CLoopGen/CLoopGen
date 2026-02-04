#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  int C1;
extern  int C2;
extern  int h;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i0 = 0; i0 < h; i0++) {
    int temp_dst_off = 0;
    for (int j = 0; j < 8; j += 4) {
        dst[temp_dst_off + 0] = (((dst[temp_dst_off + 0]) + cm[(-(src[temp_dst_off - 1] + src[temp_dst_off + 2]) + src[temp_dst_off + 0] * C1 + src[temp_dst_off + 1] * C2 + 8) >> 4] + 1) >> 1);
        dst[temp_dst_off + 1] = (((dst[temp_dst_off + 1]) + cm[(-(src[temp_dst_off + 0] + src[temp_dst_off + 3]) + src[temp_dst_off + 1] * C1 + src[temp_dst_off + 2] * C2 + 8) >> 4] + 1) >> 1);
        dst[temp_dst_off + 2] = (((dst[temp_dst_off + 2]) + cm[(-(src[temp_dst_off + 1] + src[temp_dst_off + 4]) + src[temp_dst_off + 2] * C1 + src[temp_dst_off + 3] * C2 + 8) >> 4] + 1) >> 1);
        dst[temp_dst_off + 3] = (((dst[temp_dst_off + 3]) + cm[(-(src[temp_dst_off + 2] + src[temp_dst_off + 5]) + src[temp_dst_off + 3] * C1 + src[temp_dst_off + 4] * C2 + 8) >> 4] + 1) >> 1);
        temp_dst_off += 4;
    }
    dst += dstStride;
    src += srcStride;
}
}
