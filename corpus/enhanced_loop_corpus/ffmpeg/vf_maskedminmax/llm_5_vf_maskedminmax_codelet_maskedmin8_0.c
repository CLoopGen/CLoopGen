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
        int d1 = src[x] - f1[x];
        int d2 = src[x] - f2[x];
        int abs_d1 = d1 ^ (d1 >> 31);
        int abs_d2 = d2 ^ (d2 >> 31);
        if ((abs_d2 - (d2 >> 31)) < (abs_d1 - (d1 >> 31)))
            dst[x] = f2[x];
        else
            dst[x] = f1[x];
    }
}
