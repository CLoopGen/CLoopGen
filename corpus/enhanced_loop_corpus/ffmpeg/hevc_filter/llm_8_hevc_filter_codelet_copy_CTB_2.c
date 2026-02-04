#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int width;
extern int height;
extern ptrdiff_t stride_dst;
extern ptrdiff_t stride_src;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    for (i = 0; i < height; i += 2) {
        for (j = 0; j < width; j++) {
            dst[j] = src[j];
            if (i + 1 < height) {
                ((uint8_t*)((char*)dst + stride_dst))[j] = ((uint8_t*)((char*)src + stride_src))[j];
            }
        }
        dst += 2 * stride_dst;
        src += 2 * stride_src;
    }
}
