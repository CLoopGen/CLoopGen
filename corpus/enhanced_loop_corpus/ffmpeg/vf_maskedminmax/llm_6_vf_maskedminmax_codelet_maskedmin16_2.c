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
    uint16_t temp_diff2, temp_diff1;
    for (int x = 0; x < w; x++) {
        temp_diff2 = src[x] > f2[x] ? src[x] - f2[x] : f2[x] - src[x];
        temp_diff1 = src[x] > f1[x] ? src[x] - f1[x] : f1[x] - src[x];
        dst[x] = temp_diff2 < temp_diff1 ? f2[x] : f1[x];
    }
}
