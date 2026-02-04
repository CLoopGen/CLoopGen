#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int srcStride;
extern int dstStride[];
extern int srcSliceH;
extern int inc_size;
extern int width;
extern uint8_t *dest[3];
extern int x;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int h, x;
    for (h = 0; h < srcSliceH; h += 2) {
        for (x = 0; x < width; x += 4) {
            int max_x = (x + 4 <= width) ? x + 4 : width;
            int max_h = (h + 2 <= srcSliceH) ? h + 2 : srcSliceH;
            for (int hy = h; hy < max_h; hy++) {
                uint8_t *src_line = src + hy * srcStride;
                uint8_t *dst0 = dest[0] + hy * dstStride[0];
                uint8_t *dst1 = dest[1] + hy * dstStride[1];
                uint8_t *dst2 = dest[2] + hy * dstStride[2];
                for (int xx = x; xx < max_x; xx++) {
                    int idx = xx * inc_size;
                    dst0[xx] = src_line[idx + 0];
                    dst1[xx] = src_line[idx + 1];
                    dst2[xx] = src_line[idx + 2];
                }
            }
        }
    }
}
