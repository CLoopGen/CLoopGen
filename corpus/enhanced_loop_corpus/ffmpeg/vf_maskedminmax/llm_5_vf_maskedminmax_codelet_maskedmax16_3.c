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
        uint16_t val1 = src[x] - f1[x];
        uint16_t val2 = src[x] - f2[x];
        uint16_t abs1 = (val1 & 0x8000) ? (uint16_t)(-val1) : val1;
        uint16_t abs2 = (val2 & 0x8000) ? (uint16_t)(-val2) : val2;
        dst[x] = abs2 > abs1 ? f2[x] : f1[x];
    }
}
