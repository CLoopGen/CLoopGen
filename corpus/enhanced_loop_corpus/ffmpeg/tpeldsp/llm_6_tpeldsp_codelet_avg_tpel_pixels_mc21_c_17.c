#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int stride;
extern int width;
extern int height;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *src_local = src;
    uint8_t *dst_local = dst;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width - 1; j++) {
            int temp1 = 3 * src_local[j] + 4 * src_local[j + 1];
            int temp2 = 2 * src_local[j + stride] + 3 * src_local[j + stride + 1];
            int sum = ((temp1 + temp2 + 6) * 2731) >> 15;
            dst_local[j] = (dst_local[j] + sum + 1) >> 1;
        }
        if (width > 0) {
            int fallback = ((3 * src_local[0] + 6) * 2731) >> 15;
            dst_local[width - 1] = (dst_local[width - 1] + fallback + 1) >> 1;
        }
        src_local += stride;
        dst_local += stride;
    }
}
