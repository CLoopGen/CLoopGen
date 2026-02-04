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
          uint8_t temp_val;
          for (x = 0; x < width; x++) {
              temp_val = src[x * step + comp];
              dst[x] = temp_val;
          }
        }
        break;
      case 2: {
          uint8_t temp_low, temp_high;
          for (x = 0; x < width; x++) {
              temp_low = src[x * step + comp * 2];
              temp_high = src[x * step + comp * 2 + 1];
              dst[x * 2] = temp_low;
              dst[x * 2 + 1] = temp_high;
          }
        }
        break;
    }
    dst += dst_linesize;
    src += src_linesize;
}
}
