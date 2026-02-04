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
    for (int x = 0; x < w; x++) {
        int32_t s = src[x], f1_val = f1[x], f2_val = f2[x];
        int32_t diff1_abs = s - f1_val;
        int32_t diff2_abs = s - f2_val;
        diff1_abs = diff1_abs >= 0 ? diff1_abs : -diff1_abs;
        diff2_abs = diff2_abs >= 0 ? diff2_abs : -diff2_abs;
        if (diff2_abs >= diff1_abs) {
            dst[x] = f1_val;
            continue;
        }
        dst[x] = f2_val;
    }
}
