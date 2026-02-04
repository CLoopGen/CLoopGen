#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern  uint16_t *src;
extern  uint16_t *f1;
extern  uint16_t *f2;
extern uint16_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int x = 0; x < w; x += 2) {
        uint16_t diff1_x0, diff2_x0, diff1_x1, diff2_x1;
        diff1_x0 = src[x] >= f1[x] ? src[x] - f1[x] : f1[x] - src[x];
        diff2_x0 = src[x] >= f2[x] ? src[x] - f2[x] : f2[x] - src[x];
        dst[x] = diff2_x0 < diff1_x0 ? f2[x] : f1[x];

        if (x + 1 < w) {
            diff1_x1 = src[x+1] >= f1[x+1] ? src[x+1] - f1[x+1] : f1[x+1] - src[x+1];
            diff2_x1 = src[x+1] >= f2[x+1] ? src[x+1] - f2[x+1] : f2[x+1] - src[x+1];
            dst[x+1] = diff2_x1 < diff1_x1 ? f2[x+1] : f1[x+1];
        }
    }
}
