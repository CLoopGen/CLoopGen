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
        int32_t s = src[x];
        int32_t a1 = s - f1[x];
        int32_t a2 = s - f2[x];
        int32_t abs_a1 = (a1 ^ (a1 >> 31)) - (a1 >> 31);
        int32_t abs_a2 = (a2 ^ (a2 >> 31)) - (a2 >> 31);
        dst[x] = abs_a2 > abs_a1 ? f2[x] : f1[x];
    }
}
