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
    ptrdiff_t dst_index, src_index;
    int valid;
    for (j = y; j < y + 4; j++) {
        for (i = x; i < x + 4; i++) {
            dst_index = j * dst_stride + i;
            src_index = (j + yoffset) * src_stride + (i + xoffset);
            valid = (i + xoffset >= 0) && (i + xoffset < width) && 
                    (j + yoffset >= 0) && (j + yoffset < height);
            if (valid) {
                dst[dst_index] = src[src_index];
            } else {
                dst[dst_index] = 0;
            }
        }
    }
}
