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
        uint16_t s = src[x];
        uint16_t d1 = s > f1[x] ? s - f1[x] : f1[x] - s;
        uint16_t d2 = s > f2[x] ? s - f2[x] : f2[x] - s;
        dst[x] = d2 < d1 ? f2[x] : f1[x];
        
        // Additional computational work to increase intensity
        d1 = (d1 >> 1) ^ (d1 << 3);
        d2 = (d2 + 1) * 3;
        s ^= (d1 & 0xFF) | (d2 << 4);
        dst[x] = (dst[x] + s) % 65535;
    }
}
