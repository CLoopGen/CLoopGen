#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  int w;
extern  int h;
extern  uint8_t *cm;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j, i;
    uint8_t *src_local = src;
    uint8_t *dst_local = dst;
    for (j = 0; j < h - 2; j++) {
        for (i = 0; i < w - 2; i++) {
            int s0 = (src_local[i + 0 + srcStride * 0] + src_local[i + 1 + srcStride * 0] + src_local[i + 2 + srcStride * 0]) >> 1;
            int s1 = (src_local[i + 0 + srcStride * 1] + src_local[i + 1 + srcStride * 1] + src_local[i + 2 + srcStride * 1]) >> 1;
            int s2 = (src_local[i + 0 + srcStride * 2] + src_local[i + 1 + srcStride * 2] + src_local[i + 2 + srcStride * 2]) >> 1;
            int avg = (s0 + s1 + s2) >> 2;
            int idx = (avg + 128) >> 8;
            if (idx < 0) idx = 0;
            else if (idx > 255) idx = 255;
            dst_local[i] = ((dst_local[i] + cm[idx] + 1) >> 1);
        }
        src_local += srcStride;
        dst_local += dstStride;
    }
}
