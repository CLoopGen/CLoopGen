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
for (j = y; j < y + 4; j++)
    for (i = x; i < x + 4; i++) {
        int src_i = i + xoffset;
        int src_j = j + yoffset;
        unsigned char val = 0;
        if (src_i >= 0 && src_i < width && src_j >= 0 && src_j < height)
            val = src[src_j * src_stride + src_i];
        dst[j * dst_stride + i] = val;
    }
}
