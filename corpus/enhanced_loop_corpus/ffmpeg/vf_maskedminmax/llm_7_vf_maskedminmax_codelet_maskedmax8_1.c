#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern  uint8_t *f1;
extern  uint8_t *f2;
extern int w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int x = 0; x < w; x += 2) {
        if (x + 1 < w) {
            uint8_t diff1_0 = (src[x] - f1[x] >= 0) ? (src[x] - f1[x]) : -(src[x] - f1[x]);
            uint8_t diff2_0 = (src[x] - f2[x] >= 0) ? (src[x] - f2[x]) : -(src[x] - f2[x]);
            uint8_t diff1_1 = (src[x+1] - f1[x+1] >= 0) ? (src[x+1] - f1[x+1]) : -(src[x+1] - f1[x+1]);
            uint8_t diff2_1 = (src[x+1] - f2[x+1] >= 0) ? (src[x+1] - f2[x+1]) : -(src[x+1] - f2[x+1]);

            dst[x]   = diff2_0 > diff1_0 ? f2[x]   : f1[x];
            dst[x+1] = diff2_1 > diff1_1 ? f2[x+1] : f1[x+1];
        } else {
            uint8_t diff1 = (src[x] - f1[x] >= 0) ? (src[x] - f1[x]) : -(src[x] - f1[x]);
            uint8_t diff2 = (src[x] - f2[x] >= 0) ? (src[x] - f2[x]) : -(src[x] - f2[x]);
            dst[x] = diff2 > diff1 ? f2[x] : f1[x];
        }
    }
}
