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
        dst[x] = ((src[x] - f2[x]) >= 0 ? (src[x] - f2[x]) : (-(src[x] - f2[x]))) > ((src[x] - f1[x]) >= 0 ? (src[x] - f1[x]) : (-(src[x] - f1[x]))) ? f2[x] : f1[x];
        if (x + 1 < w) {
            dst[x+1] = ((src[x+1] - f2[x+1]) >= 0 ? (src[x+1] - f2[x+1]) : (-(src[x+1] - f2[x+1]))) > ((src[x+1] - f1[x+1]) >= 0 ? (src[x+1] - f1[x+1]) : (-(src[x+1] - f1[x+1]))) ? f2[x+1] : f1[x+1];
        }
    }
}
