#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char *dst;
extern ptrdiff_t dst_stride;
extern  unsigned char *src;
extern ptrdiff_t src_stride;
extern int x;
extern int y;
extern int xoffset;
extern int yoffset;
extern int width;
extern int height;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int idx = 0;
    for (idx = 0; idx < 16; idx++) {
        int j = y + (idx / 4);
        int i = x + (idx % 4);
        int src_i = i + xoffset;
        int src_j = j + yoffset;
        if (src_i >= 0 && src_i < width && src_j >= 0 && src_j < height) {
            dst[j * dst_stride + i] = src[src_j * src_stride + src_i];
        } else {
            dst[j * dst_stride + i] = 0;
        }
    }
}
