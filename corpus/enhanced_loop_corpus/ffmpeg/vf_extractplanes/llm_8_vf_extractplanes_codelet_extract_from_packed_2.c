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
for (y = 0; y < height; y++) {
    switch (depth) {
      case 1:
        for (x = 0; x < width; x += 2) {
            dst[x] = src[x * step + comp];
            if (x + 1 < width)
                dst[x + 1] = src[(x + 1) * step + comp];
        }
        break;
      case 2:
        for (x = 0; x < width; x += 2) {
            int idx = x * 2;
            dst[idx] = src[x * step + comp * 2];
            dst[idx + 1] = src[x * step + comp * 2 + 1];
            if (x + 1 < width) {
                dst[idx + 2] = src[(x + 1) * step + comp * 2];
                dst[idx + 3] = src[(x + 1) * step + comp * 2 + 1];
            }
        }
        break;
    }
    dst += dst_linesize;
    src += src_linesize;
}
}
