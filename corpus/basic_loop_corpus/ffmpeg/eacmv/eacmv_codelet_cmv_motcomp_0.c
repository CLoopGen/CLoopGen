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
        if (i + xoffset >= 0 && i + xoffset < width && j + yoffset >= 0 && j + yoffset < height) {
            dst[j * dst_stride + i] = src[(j + yoffset) * src_stride + i + xoffset];
        } else {
            dst[j * dst_stride + i] = 0;
        }
    }

}
