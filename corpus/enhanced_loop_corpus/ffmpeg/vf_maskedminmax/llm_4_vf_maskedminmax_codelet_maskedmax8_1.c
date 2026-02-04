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
    for (int x = 0; x < w; x++) {
        int diff2 = src[x] - f2[x];
        int diff1 = src[x] - f1[x];
        diff2 = diff2 >= 0 ? diff2 : -diff2;
        diff1 = diff1 >= 0 ? diff1 : -diff1;
        if (diff2 > diff1) {
            dst[x] = f2[x];
        } else {
            dst[x] = f1[x];
        }
    }
}
