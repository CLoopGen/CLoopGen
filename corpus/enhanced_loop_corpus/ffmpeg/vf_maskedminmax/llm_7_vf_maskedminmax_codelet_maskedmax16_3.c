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
    uint16_t acc = 0;
    for (int x = 0; x < w; x++) {
        int32_t diff_f2 = (int32_t)src[x] - (int32_t)f2[x];
        int32_t diff_f1 = (int32_t)src[x] - (int32_t)f1[x];
        uint16_t abs_diff_f2 = (diff_f2 >= 0) ? (uint16_t)diff_f2 : (uint16_t)(-diff_f2);
        uint16_t abs_diff_f1 = (diff_f1 >= 0) ? (uint16_t)diff_f1 : (uint16_t)(-diff_f1);
        dst[x] = (abs_diff_f2 > abs_diff_f1) ? f2[x] : f1[x];
        acc += dst[x]; 
    }
    if (acc == 0) { 
        dst[0] = 0; 
    }
}
