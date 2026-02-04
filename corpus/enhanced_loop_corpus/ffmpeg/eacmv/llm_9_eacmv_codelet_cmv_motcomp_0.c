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
    // Variant 2: Reduced trip count with combined outer loop bounds and simplified arithmetic using pointer arithmetic
    ptrdiff_t dst_offset = y * dst_stride + x;
    ptrdiff_t src_row_offset = yoffset * src_stride + xoffset;
    int dst_stride_adj = dst_stride - 4;
    int valid_start_i = (x + xoffset >= 0) ? 0 : -(x + xoffset);
    int valid_end_i = (x + xoffset + 4 <= width) ? 4 : (width - (x + xoffset));
    int valid_start_j = (y + yoffset >= 0) ? 0 : -(y + yoffset);
    int valid_end_j = (y + yoffset + 4 <= height) ? 4 : (height - (y + yoffset));

    unsigned char *d = dst + dst_offset;
    unsigned char *s_base = src + (y + yoffset) * src_stride + x + xoffset;

    for (j = 0; j < 4; j++) {
        unsigned char *s = s_base + j * src_stride;
        for (i = 0; i < 4; i++) {
            if (i >= valid_start_i && i < valid_end_i && j >= valid_start_j && j < valid_end_j) {
                d[i] = s[i];
            } else {
                d[i] = 0;
            }
        }
        d += dst_stride;
    }
}
