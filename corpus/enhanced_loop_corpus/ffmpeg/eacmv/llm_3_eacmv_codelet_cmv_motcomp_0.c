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
    // Variant 2: Strided memory access with reversed loop order (j from high to low, i inner loop reversed)
    int j_end = y + 4;
    int i_end = x + 4;

    for (int j = j_end - 1; j >= y; j--) {
        for (int i = i_end - 1; i >= x; i--) {
            int src_idx_j = j + yoffset;
            int src_idx_i = i + xoffset;
            if (src_idx_i >= 0 && src_idx_i < width && src_idx_j >= 0 && src_idx_j < height) {
                dst[j * dst_stride + i] = src[src_idx_j * src_stride + src_idx_i];
            } else {
                dst[j * dst_stride + i] = 0;
            }
        }
    }
}
