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
        int diff1 = src[x] - f2[x];
        int abs_diff1 = diff1 >= 0 ? diff1 : -diff1;
        int diff2 = src[x] - f1[x];
        int abs_diff2 = diff2 >= 0 ? diff2 : -diff2;
        dst[x] = abs_diff1 > abs_diff2 ? f2[x] : f1[x];
        
        if (x + 1 < w) {
            diff1 = src[x+1] - f2[x+1];
            abs_diff1 = diff1 >= 0 ? diff1 : -diff1;
            diff2 = src[x+1] - f1[x+1];
            abs_diff2 = diff2 >= 0 ? diff2 : -diff2;
            dst[x+1] = abs_diff1 > abs_diff2 ? f2[x+1] : f1[x+1];
        }
    }
}
