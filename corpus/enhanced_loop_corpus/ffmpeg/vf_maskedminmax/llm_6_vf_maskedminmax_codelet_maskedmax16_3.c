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
    uint16_t temp_f1, temp_f2, temp_src;
    for (int x = 0; x < w; x++) {
        temp_src = src[x];
        temp_f1 = f1[x];
        temp_f2 = f2[x];
        uint16_t diff1 = (temp_src > temp_f2) ? (temp_src - temp_f2) : (temp_f2 - temp_src);
        uint16_t diff2 = (temp_src > temp_f1) ? (temp_src - temp_f1) : (temp_f1 - temp_src);
        dst[x] = (diff1 > diff2) ? temp_f2 : temp_f1;
    }
}
