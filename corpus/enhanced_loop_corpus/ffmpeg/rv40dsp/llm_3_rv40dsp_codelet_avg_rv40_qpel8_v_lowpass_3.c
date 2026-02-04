#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  int w;
extern  int C1;
extern  int C2;
extern  int SHIFT;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < w; i++) {
    const int offset = i * dstStride;
    const uint8_t* s = &src[i * srcStride];
    const int src_offsets[] = {-2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8};
    int src_cache[11];
    for (int j = 0; j < 11; j++) {
        src_cache[j] = s[src_offsets[j] * srcStride];
    }
    uint8_t temp_dst[8];
    temp_dst[0] = (((dst[offset + 0 * dstStride]) + cm[(src_cache[0] + src_cache[3] - 5 * (src_cache[1] + src_cache[2]) + src_cache[2] * C1 + src_cache[3] * C2 + (1 << (SHIFT - 1))) >> SHIFT] + 1) >> 1);
    temp_dst[1] = (((dst[offset + 1 * dstStride]) + cm[(src_cache[1] + src_cache[4] - 5 * (src_cache[2] + src_cache[3]) + src_cache[3] * C1 + src_cache[4] * C2 + (1 << (SHIFT - 1))) >> SHIFT] + 1) >> 1);
    temp_dst[2] = (((dst[offset + 2 * dstStride]) + cm[(src_cache[2] + src_cache[5] - 5 * (src_cache[3] + src_cache[4]) + src_cache[4] * C1 + src_cache[5] * C2 + (1 << (SHIFT - 1))) >> SHIFT] + 1) >> 1);
    temp_dst[3] = (((dst[offset + 3 * dstStride]) + cm[(src_cache[3] + src_cache[6] - 5 * (src_cache[4] + src_cache[5]) + src_cache[5] * C1 + src_cache[6] * C2 + (1 << (SHIFT - 1))) >> SHIFT] + 1) >> 1);
    temp_dst[4] = (((dst[offset + 4 * dstStride]) + cm[(src_cache[4] + src_cache[7] - 5 * (src_cache[5] + src_cache[6]) + src_cache[6] * C1 + src_cache[7] * C2 + (1 << (SHIFT - 1))) >> SHIFT] + 1) >> 1);
    temp_dst[5] = (((dst[offset + 5 * dstStride]) + cm[(src_cache[5] + src_cache[8] - 5 * (src_cache[6] + src_cache[7]) + src_cache[7] * C1 + src_cache[8] * C2 + (1 << (SHIFT - 1))) >> SHIFT] + 1) >> 1);
    temp_dst[6] = (((dst[offset + 6 * dstStride]) + cm[(src_cache[6] + src_cache[9] - 5 * (src_cache[7] + src_cache[8]) + src_cache[8] * C1 + src_cache[9] * C2 + (1 << (SHIFT - 1))) >> SHIFT] + 1) >> 1);
    temp_dst[7] = (((dst[offset + 7 * dstStride]) + cm[(src_cache[7] + src_cache[10] - 5 * (src_cache[8] + src_cache[9]) + src_cache[9] * C1 + src_cache[10] * C2 + (1 << (SHIFT - 1))) >> SHIFT] + 1) >> 1);
    for (int j = 0; j < 8; j++) {
        dst[offset + j * dstStride] = temp_dst[j];
    }
}
}
