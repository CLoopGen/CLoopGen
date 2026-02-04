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
switch (depth) {
  case 1:
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++)
            dst[x] = src[x * step + comp];
        dst += dst_linesize;
        src += src_linesize;
    }
    break;
  case 2:
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            dst[x * 2] = src[x * step + comp * 2];
            dst[x * 2 + 1] = src[x * step + comp * 2 + 1];
        }
        dst += dst_linesize;
        src += src_linesize;
    }
    break;
}
}
