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
    for (j = 0; j < h; j++) {
        for (i = 0; i < w - 2; i++) {
            int sum = 36 * src_local[i + srcStride * 0] +
                      54 * src_local[i + 1 + srcStride * 0] +
                       6 * src_local[i + 2 + srcStride * 0] +
                      54 * src_local[i + srcStride * 1] +
                      81 * src_local[i + 1 + srcStride * 1] +
                       9 * src_local[i + 2 + srcStride * 1] +
                       6 * src_local[i + srcStride * 2] +
                       9 * src_local[i + 1 + srcStride * 2] +
                       1 * src_local[i + 2 + srcStride * 2];
            dst_local[i] = ((dst_local[i] + cm[(sum + 128) >> 8] + 1) >> 1);
        }
        src_local += srcStride;
        dst_local += dstStride;
    }
}
