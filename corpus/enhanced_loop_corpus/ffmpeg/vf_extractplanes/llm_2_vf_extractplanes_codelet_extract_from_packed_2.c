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
      case 1: {
        uint8_t *d = dst;
        const uint8_t *s = src + comp;
        for (x = 0; x < width; x++) {
            d[x] = s[x * step];
        }
        break;
      }
      case 2: {
        uint8_t *d = dst;
        const uint8_t *s = src + comp * 2;
        for (x = 0; x < width; x++) {
            int src_idx = x * step;
            d[x * 2] = s[src_idx];
            d[x * 2 + 1] = s[src_idx + 1];
        }
        break;
      }
    }
    dst += dst_linesize;
    src += src_linesize;
}
}
