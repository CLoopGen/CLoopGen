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
            int diff_src_f2_x = src[x] - f2[x];
            int diff_src_f1_x = src[x] - f1[x];
            int abs_diff2_x = (diff_src_f2_x >= 0) ? diff_src_f2_x : -diff_src_f2_x;
            int abs_diff1_x = (diff_src_f1_x >= 0) ? diff_src_f1_x : -diff_src_f1_x;

            int diff_src_f2_x1 = src[x+1] - f2[x+1];
            int diff_src_f1_x1 = src[x+1] - f1[x+1];
            int abs_diff2_x1 = (diff_src_f2_x1 >= 0) ? diff_src_f2_x1 : -diff_src_f2_x1;
            int abs_diff1_x1 = (diff_src_f1_x1 >= 0) ? diff_src_f1_x1 : -diff_src_f1_x1;

            dst[x]   = (abs_diff2_x < abs_diff1_x) ? f2[x] : f1[x];
            dst[x+1] = (abs_diff2_x1 < abs_diff1_x1) ? f2[x+1] : f1[x+1];
        } else {
            int diff_src_f2 = src[x] - f2[x];
            int diff_src_f1 = src[x] - f1[x];
            int abs_diff2 = (diff_src_f2 >= 0) ? diff_src_f2 : -diff_src_f2;
            int abs_diff1 = (diff_src_f1 >= 0) ? diff_src_f1 : -diff_src_f1;
            dst[x] = (abs_diff2 < abs_diff1) ? f2[x] : f1[x];
        }
    }
}
