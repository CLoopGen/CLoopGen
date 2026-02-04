#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int dst_linesize;
extern  uint8_t *src;
extern int src_linesize;
extern int width;
extern int height;
extern int depth;
extern int step;
extern int comp;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height; y += 2) {
    uint8_t *dst1 = dst, *dst2 = dst + dst_linesize;
    uint8_t *src1 = src, *src2 = src + src_linesize;
    int valid_height = y + 1 < height;

    switch (depth) {
      case 1:
        for (x = 0; x < width; x++) {
            dst1[x] = src1[x * step + comp];
            if (valid_height)
                dst2[x] = src2[x * step + comp];
        }
        break;
      case 2:
        for (x = 0; x < width; x++) {
            dst1[x * 2] = src1[x * step + comp * 2];
            dst1[x * 2 + 1] = src1[x * step + comp * 2 + 1];
            if (valid_height) {
                dst2[x * 2] = src2[x * step + comp * 2];
                dst2[x * 2 + 1] = src2[x * step + comp * 2 + 1];
            }
        }
        break;
    }
    dst += dst_linesize * (valid_height ? 2 : 1);
    src += src_linesize * (valid_height ? 2 : 1);
}
}
