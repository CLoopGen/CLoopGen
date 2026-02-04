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
            int diff1_0 = src[x] - f2[x];
            int abs_diff1_0 = diff1_0 >= 0 ? diff1_0 : -diff1_0;
            int diff2_0 = src[x] - f1[x];
            int abs_diff2_0 = diff2_0 >= 0 ? diff2_0 : -diff2_0;
            dst[x] = abs_diff1_0 < abs_diff2_0 ? f2[x] : f1[x];

            int diff1_1 = src[x+1] - f2[x+1];
            int abs_diff1_1 = diff1_1 >= 0 ? diff1_1 : -diff1_1;
            int diff2_1 = src[x+1] - f1[x+1];
            int abs_diff2_1 = diff2_1 >= 0 ? diff2_1 : -diff2_1;
            dst[x+1] = abs_diff1_1 < abs_diff2_1 ? f2[x+1] : f1[x+1];
        } else {
            int diff1 = src[x] - f2[x];
            int abs_diff1 = diff1 >= 0 ? diff1 : -diff1;
            int diff2 = src[x] - f1[x];
            int abs_diff2 = diff2 >= 0 ? diff2 : -diff2;
            dst[x] = abs_diff1 < abs_diff2 ? f2[x] : f1[x];
        }
    }
}
